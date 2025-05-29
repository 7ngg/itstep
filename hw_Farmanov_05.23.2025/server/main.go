package main

import (
	"database/sql"
	"fmt"
	"log"
	"net/http"
	"os"
	"sampleapp/internal/auth"
	"sampleapp/internal/database"
	"sampleapp/internal/handler"
	"strconv"
	"time"

	"github.com/joho/godotenv"
	_ "modernc.org/sqlite"
)

func main() {
	godotenv.Load()

	port := os.Getenv("API_PORT")
	if port == "" {
		port = "8080"
	}

	jwtSecret := os.Getenv("JWT_SECRET")
	if jwtSecret == "" {
		log.Fatal("jwt secret must be configured")
	}

	tokenExpiresIn, err := strconv.Atoi(os.Getenv("JWT_EXPIRES"))
	if err != nil {
		tokenExpiresIn = 10
	}

	connection, err := sql.Open("sqlite", "data.db")
	if err != nil {
		log.Fatal("cannot connect to database")
	}
	defer connection.Close()

	cfg := handler.ApiConfig{
		DB: database.New(connection),
		JWT: auth.JWTConfig{
			Secret:         jwtSecret,
			TokenExpiresIn: time.Minute * time.Duration(tokenExpiresIn),
		},
	}

	mux := cfg.NewServeMux()
	srv := http.Server{
        Addr:    fmt.Sprintf("0.0.0.0:%s", port),
		Handler: mux,
	}

	log.Printf("starting server on :%s", port)
	log.Fatal(srv.ListenAndServe())
}
