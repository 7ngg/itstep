-- +goose Up
-- +goose StatementBegin
ALTER TABLE users
ADD COLUMN img_url TEXT NOT NULL DEFAULT '';
-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
ALTER TABLE users
DROP COLUMN img_url;
-- +goose StatementEnd
