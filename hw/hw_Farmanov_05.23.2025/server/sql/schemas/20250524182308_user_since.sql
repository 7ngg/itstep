-- +goose Up
-- +goose StatementBegin
ALTER TABLE users
ADD COLUMN created_at INTEGER NOT NULL;
-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
ALTER TABLE users
DROP COLUMN created_at;
-- +goose StatementEnd
