"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.JwtSettings = void 0;
const header = process.env.JWT_HEADER;
const secret = process.env.JWT_SECRET;
exports.JwtSettings = {
    header,
    secret,
};
