"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.mongo = exports.server = void 0;
const dotenv_1 = __importDefault(require("dotenv"));
dotenv_1.default.config();
const serverHost = process.env.HOST || "localhost";
const serverPort = process.env.PORT ? Number(process.env.PORT) : 3000;
exports.server = {
    host: serverHost,
    port: serverPort,
};
const mongoUrl = process.env.MONGO_URL;
const mongoTable = process.env.MONGO_TABLE;
exports.mongo = {
    url: mongoUrl,
    table: mongoTable,
    connectionString: `mongodb://${mongoUrl}/${mongoTable}`,
};
