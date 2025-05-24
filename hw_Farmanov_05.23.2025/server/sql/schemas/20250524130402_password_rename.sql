-- +goose Up
-- +goose StatementBegin
ALTER TABLE users
RENAME COLUMN password TO password_hash;
-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
ALTER TABLE users
RENAME COLUMN "password_hash" TO password;
-- +goose StatementEnd
