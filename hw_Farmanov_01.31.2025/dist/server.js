"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
require("dotenv").config();
const express_1 = __importDefault(require("express"));
const server_1 = require("./config/server");
const auth_1 = __importDefault(require("./routes/auth"));
const users_1 = __importDefault(require("./routes/users"));
const mongoose_1 = __importDefault(require("mongoose"));
const mongo_1 = require("./config/mongo");
mongoose_1.default
    .connect(mongo_1.Mongo.connectionString)
    .then(() => console.log(`--> Connected to ${mongo_1.Mongo.db}`))
    .catch((err) => {
    console.error("Error connecting mongo", err);
    process.exit(-1);
});
const app = (0, express_1.default)();
app.use(express_1.default.json());
app.get("/api/healthcheck", (_req, res) => {
    res.json({ hello: "world" });
});
app.use("/api/auth", auth_1.default);
app.use("/api/users", users_1.default);
app.listen(server_1.Server.port, () => {
    console.info(`--> Running on http://${server_1.Server.host}:${server_1.Server.port}`);
});
