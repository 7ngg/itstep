package handler

import (
	"encoding/json"
	"log"
	"math"
	"net/http"
	"sampleapp/internal/database"
	"time"
)

type userDto struct {
	ID            string `json:"id"`
	Username      string `json:"username"`
	ImgUrl        string `json:"imgUrl"`
	MemberForDays int    `json:"memberForDays"`
}

func UserToResponse(u database.User) userDto {
	memberFor := time.Since(time.Unix(u.CreatedAt, 0))
	return userDto{
		u.ID,
		u.Username,
		u.ImgUrl,
		int(math.Ceil(memberFor.Hours() / 24)),
	}
}

func extractAuthBody(r *http.Request) (authRequest, error) {
	defer r.Body.Close()

	body := authRequest{}
	err := json.NewDecoder(r.Body).Decode(&body)
	if err != nil {
		return authRequest{}, err
	}

	return body, nil
}

func respondWithJson(w http.ResponseWriter, code int, payload any) {
	w.Header().Add("Content-Type", "application/json")

	json, err := json.Marshal(payload)
	if err != nil {
		log.Printf("error marshaling json: %s", err)
		w.WriteHeader(http.StatusInternalServerError)
		return
	}

	w.WriteHeader(code)
	w.Write(json)
}

func respondWithError(w http.ResponseWriter, code int, msg string, err error) {
	if err != nil {
		log.Println(err)
	}

	if code > 499 {
		log.Printf("--> reponding with 5XX status error: %s", err)
	}

	type errorResponse struct {
		Error string `json:"error"`
		Code  int    `json:"code"`
	}

	respondWithJson(w, code, errorResponse{
		Error: msg,
		Code:  code,
	})
}
