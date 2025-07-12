-- +goose Up
-- +goose StatementBegin
CREATE INDEX username_idx ON  users(username);
-- +goose StatementEnd

-- +goose Down
-- +goose StatementBegin
DROP INDEX username_idx;
-- +goose StatementEnd
