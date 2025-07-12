-- +goose Up
-- +goose StatementBegin
CREATE TABLE users(
    id TEXT PRIMARY KEY,
    username TEXT NOT NULL,
    password TEXT NOT NULL
);
-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
DROP TABLE users;
-- +goose StatementEnd
