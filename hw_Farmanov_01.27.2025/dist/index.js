"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const mongoose_1 = __importDefault(require("mongoose"));
const config_1 = require("./config/config");
const express_1 = __importDefault(require("express"));
const user_1 = require("./entities/user");
const logging_1 = require("./middlewares/logging");
const routeNofDound_1 = require("./middlewares/routeNofDound");
const app = (0, express_1.default)();
function Main() {
    return __awaiter(this, void 0, void 0, function* () {
        app.use(express_1.default.json());
        app.use(logging_1.logRequest);
        try {
            yield mongoose_1.default.connect(config_1.mongo.connectionString);
            console.log("--> Connected");
        }
        catch (err) {
            console.error("Error connecting mongo:", err);
        }
        app.get("/users", (_req, res) => {
            user_1.UserModel.find().then((users) => res.status(200).json(users));
        });
        app.get("/users/:id", (req, res) => {
            const id = req.params.id;
            if (!mongoose_1.default.Types.ObjectId.isValid(id)) {
                res.status(400).json({ message: "Invalid id type" });
                return;
            }
            user_1.UserModel.findById(id)
                .then((user) => {
                console.log(user);
                if (!user) {
                    return res.status(404).json({ message: "User does not exist" });
                }
                res.status(200).json(user);
            })
                .catch((err) => console.error(err.message));
        });
        app.use(routeNofDound_1.routeNotFound);
        app.listen(config_1.server.port, () => {
            console.warn(`--> Server running on http://${config_1.server.host}:${config_1.server.port}`);
        });
    });
}
Main();
