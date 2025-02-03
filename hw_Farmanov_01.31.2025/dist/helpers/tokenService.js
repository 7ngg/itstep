"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.generateToken = generateToken;
const jsonwebtoken_1 = __importDefault(require("jsonwebtoken"));
const jwt_1 = require("../config/jwt");
function generateToken(user) {
    const data = {
        username: user.username,
    };
    const secret = jwt_1.JwtSettings.secret;
    if (!secret) {
        throw new Error("jwt secret not found");
    }
    const token = jsonwebtoken_1.default.sign(data, secret);
    return token;
}
