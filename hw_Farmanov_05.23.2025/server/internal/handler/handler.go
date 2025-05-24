package handler

import (
	"net/http"
	"sampleapp/internal/auth"
	"sampleapp/internal/database"
)

type ApiConfig struct {
	DB  *database.Queries
	JWT auth.JWTConfig
}

func (cfg *ApiConfig) NewServeMux() *http.ServeMux {
	mux := http.NewServeMux()

	mux.HandleFunc("GET /api/healthcheck", cfg.handlerHealthCheck)

	mux.HandleFunc("POST /auth/sign-up", cfg.handlerSignUp)
	mux.HandleFunc("POST /auth/sign-in", cfg.handlerSignIn)

	mux.HandleFunc("GET /users", cfg.GetAllUsers)

	return mux
}
