package handler

import (
	"errors"
	"log"
	"net/http"
	"sampleapp/internal/auth"
)

func (cfg *ApiConfig) GetAllUsers(w http.ResponseWriter, r *http.Request) {
	token, err := r.Cookie("accessToken")
	if err != nil {
		switch {
		case errors.Is(err, http.ErrNoCookie):
			respondWithError(w, http.StatusUnauthorized,
				"authorization cookie not found", err)
		default:
			respondWithError(w, http.StatusInternalServerError, "server error",
				err)
		}

		return
	}

	err = auth.ValidateJWT(token.Value, cfg.JWT.Secret)
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
