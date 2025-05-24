package auth

import (
	"errors"
	"fmt"
	"net/http"
	"strings"
	"time"

	"github.com/golang-jwt/jwt/v5"
	"golang.org/x/crypto/bcrypt"
)

func HashPasword(password string) (string, error) {
	bytes := []byte(password)
	hash, err := bcrypt.GenerateFromPassword(bytes, 15)
	if err != nil {
		return "", err
	}

	return string(hash), err
}

func CheckPasswordHash(password, hash string) error {
	hashBytes := []byte(hash)
	passwordBytes := []byte(password)

	return bcrypt.CompareHashAndPassword(hashBytes, passwordBytes)
}

func MakeJWT(userID string, tokenSecret string, expiresIn time.Duration) (string, error) {
	claims := jwt.RegisteredClaims{
		Subject:   userID,
		IssuedAt:  jwt.NewNumericDate(time.Now().UTC()),
		ExpiresAt: jwt.NewNumericDate(time.Now().UTC().Add(expiresIn)),
	}

	token := jwt.NewWithClaims(jwt.SigningMethodHS512, claims)

	return token.SignedString([]byte(tokenSecret))
}

func RetrieveJWT(h http.Header) string {
	authHeader := h.Get("Authorization")

	parts := strings.Split(authHeader, " ")
	if len(parts) != 2 || strings.ToLower(parts[0]) != "bearer" {
		return ""
	}

	return parts[1]
}

func ValidateJWT(token, secret string) error {
	t, err := jwt.Parse(token, func(t *jwt.Token) (any, error) {
		if _, ok := t.Method.(*jwt.SigningMethodHMAC); !ok {
			return nil, fmt.Errorf("unexpected signing method: %v", t.Header["alg"])
		}

		return []byte(secret), nil
	})

	if err != nil {
		return err
	}

	if !t.Valid {
		return errors.New("token expired")
	}

	return nil
}
