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
const routeNotFound_1 = require("./middlewares/routeNotFound");
const node_process_1 = require("node:process");
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
            (0, node_process_1.exit)(-1);
        }
        app.get("/users", (_req, res) => {
            user_1.UserModel.find().then((users) => res.status(200).json(users));
        });
        app.get("/users/:id", (req, res) => __awaiter(this, void 0, void 0, function* () {
            const id = req.params.id;
            const user = yield user_1.UserModel.findById(id);
            if (!user) {
                res.sendStatus(404);
                return;
            }
            res.status(200).send(user);
        }));
        app.post("/users", (req, res) => __awaiter(this, void 0, void 0, function* () {
            const body = req.body;
            if (!body.username || !body.password) {
                res.status(400).json("Missing required field");
                return;
            }
            const newUser = Object.assign(Object.assign({}, body), { doj: new Date() });
            try {
                user_1.UserModel.create(newUser);
                res
                    .status(201)
                    .send(yield user_1.UserModel.findOne({ username: newUser.username }));
            }
            catch (err) {
                res.status(500).send(err);
                return;
            }
        }));
        app.delete("/users/:id", (req, res) => __awaiter(this, void 0, void 0, function* () {
            const id = req.params.id;
            if (!mongoose_1.default.isValidObjectId(id)) {
                res.status(400).send("Invalid id format");
                return;
            }
            yield user_1.UserModel.findOneAndDelete({ _id: id });
            res.sendStatus(204);
        }));
        app.use(routeNotFound_1.routeNotFound);
        app.listen(config_1.server.port, () => {
            console.warn(`--> Server running on http://${config_1.server.host}:${config_1.server.port}`);
        });
    });
}
Main();
