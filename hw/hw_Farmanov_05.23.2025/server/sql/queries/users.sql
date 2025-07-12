-- name: CreateUser :one
INSERT INTO users(id, username, password_hash, created_at)
VALUES(?, ?, ?, ?)
RETURNING *;

-- name: GetAllUsers :many
SELECT * FROM users
ORDER BY username;

-- name: GetById :one
SELECT * FROM users
WHERE users.id = ?;

-- name: GetByUsername :one
SELECT * FROM users
WHERE users.username = ?;
