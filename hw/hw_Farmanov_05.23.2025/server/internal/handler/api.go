package handler

import "net/http"

func (h *ApiConfig) handlerHealthCheck(w http.ResponseWriter, r *http.Request) {
	respondWithJson(
		w, http.StatusOK,
		struct {
			Hello string `json:"hello"`
		}{
			Hello: "world",
		})
}
