package handler

import (
	"fmt"
	"log"
	"net/http"
	"sampleapp/internal/auth"
	"sampleapp/internal/database"
	"strings"
	"time"

	"github.com/google/uuid"
)

type authRequest struct {
	Username string `json:"username"`
	Password string `json:"password"`
}

func (cfg *ApiConfig) handlerSignIn(w http.ResponseWriter, r *http.Request) {
	type singInResponse struct {
		AccessToken string `json:"accessToken"`
	}

	body, err := extractAuthBody(r)
	if err != nil {
		msg := "unable to extract request body"
		log.Printf("%s: %s", msg, err)
		respondWithError(w, http.StatusInternalServerError, msg, err)
		return
	}

	user, err := cfg.DB.GetByUsername(r.Context(), body.Username)
	if err != nil {
		msg := fmt.Sprintf("user '%s' was not found", body.Username)
		respondWithError(w, http.StatusNotFound, msg, err)
		return
	}

	if err = auth.CheckPasswordHash(body.Password, user.PasswordHash); err != nil {
		respondWithError(w, http.StatusUnauthorized, "invalid credentials", err)
		return
	}

	token, err := auth.MakeJWT(user.ID, cfg.JWT.Secret, cfg.JWT.TokenExpiresIn)
	if err != nil {
		msg := fmt.Sprintf("unable to generate token for '%s'", user.ID)
		log.Printf("%s: %s", msg, err)
		respondWithError(w, http.StatusInternalServerError, msg, err)
	}

	cookie := http.Cookie{
		Name:     "accessToken",
		Value:    token,
		MaxAge:   int(cfg.JWT.TokenExpiresIn),
		Path:     "/",
		HttpOnly: true,
		Secure:   true,
		SameSite: http.SameSiteLaxMode,
	}

	http.SetCookie(w, &cookie)
	respondWithJson(w, http.StatusOK, UserToResponse(user))
}

func (cfg *ApiConfig) handlerSignUp(w http.ResponseWriter, r *http.Request) {
	body, err := extractAuthBody(r)
	if err != nil {
		msg := "unable to extract request body"
		log.Printf("%s: %s", msg, err)
		respondWithError(w, http.StatusInternalServerError, msg, err)
		return
	}

	if len(strings.TrimSpace(body.Username)) == 0 || len(strings.TrimSpace(body.Password)) == 0 {
		msg := "invalid sign-up inputs"
		go log.Printf("%s: [%s:%s]", msg, body.Username, body.Password)
		respondWithError(w, http.StatusBadRequest, msg, nil)
		return
	}

	hash, err := auth.HashPasword(body.Password)
	if err != nil {
		respondWithError(w, http.StatusInternalServerError,
			"unable to hash password", err)
	}

	user, err := cfg.DB.CreateUser(r.Context(), database.CreateUserParams{
		ID:           uuid.NewString(),
		Username:     body.Username,
		PasswordHash: hash,
		CreatedAt:    time.Now().UTC().Unix(),
	})
	if err != nil {
		msg := "unable to create user"
		go log.Printf("%s: %s", msg, err)
		respondWithError(w, http.StatusInternalServerError, msg, err)
		return
	}

	respondWithJson(w, http.StatusCreated, UserToResponse(user))
}
