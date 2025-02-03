"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.Server = void 0;
const host = process.env.SERVER_HOST;
const port = Number(process.env.SERVER_PORT);
exports.Server = {
    host,
    port,
};
