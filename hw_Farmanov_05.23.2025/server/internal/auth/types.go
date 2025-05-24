package auth

import "time"

type JWTConfig struct {
	Secret         string
	TokenExpiresIn time.Duration
}
