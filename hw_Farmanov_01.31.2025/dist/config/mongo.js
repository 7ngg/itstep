"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Mongo = void 0;
const host = process.env.MONGO_HOST;
const port = Number(process.env.MONGO_PORT);
const db = process.env.MONGO_DB;
exports.Mongo = {
    host,
    port,
    db,
    connectionString: `mongodb://${host}:${port}/${db}`,
};
