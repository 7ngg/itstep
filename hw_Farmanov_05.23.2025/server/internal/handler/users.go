package handler

import (
	"database/sql"
	"errors"
	"log"
	"net/http"
	"sampleapp/internal/auth"
)

func (cfg *ApiConfig) GetSelf(w http.ResponseWriter, r *http.Request) {
	token := auth.RetrieveJWT(r.Header)

	userId, err := auth.ValidateJWT(token, cfg.JWT.Secret)
	if err != nil {
		w.WriteHeader(http.StatusUnauthorized)
		return
	}

	user, err := cfg.DB.GetById(r.Context(), userId)
	if err != nil {
		switch {
		case errors.Is(err, sql.ErrNoRows):
			respondWithError(w, http.StatusNotFound, "user does not exist", err)
			return
		default:
			respondWithError(w, http.StatusInternalServerError,
				"unexpected server error", err)
			return
		}
	}

    respondWithJson(w, http.StatusOK, UserToResponse(user))
}

func (cfg *ApiConfig) GetAllUsers(w http.ResponseWriter, r *http.Request) {
	token := auth.RetrieveJWT(r.Header)

	_, err := auth.ValidateJWT(token, cfg.JWT.Secret)
	if err != nil {
		w.WriteHeader(http.StatusUnauthorized)
		return
	}

	users, err := cfg.DB.GetAllUsers(r.Context())
	if err != nil {
		msg := "unable to retrieve users"
		log.Printf("%s: %s", msg, err)
		respondWithError(w, http.StatusInternalServerError, msg, err)
		return
	}

	response := make([]userDto, len(users))
	for i, user := range users {
		response[i] = UserToResponse(user)
	}

	respondWithJson(w, http.StatusOK, response)
}
