"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.register = register;
exports.login = login;
const user_1 = require("../models/user");
const bcrypt_1 = __importDefault(require("bcrypt"));
const profile_1 = require("../models/profile");
const tokenService_1 = require("../helpers/tokenService");
async function register(req, res) {
    const body = req.body;
    if (!body.username || !body.password) {
        res.status(400).send("Missing required fields");
    }
    const model = await profile_1.profileModel.create({
        firstName: body.firstName,
        lastName: body.lastName,
        age: body.age,
    });
    await user_1.userModel.create({
        username: body.username,
        password: await bcrypt_1.default.hash(body.password, 10),
        profile: model,
    });
    res.status(201).send(await user_1.userModel.findOne({ username: body.username }));
}
async function login(req, res) {
    const body = req.body;
    if (!body.username || !body.password) {
        res.status(400).send("Missing required fields");
    }
    const user = await user_1.userModel.findOne({ username: body.username });
    if (!user) {
        res.status(401).send("User does not exist");
        return;
    }
    if (!(await bcrypt_1.default.compare(body.password, user.password))) {
        res.status(401).send("Invalid credentials");
        return;
    }
    const token = (0, tokenService_1.generateToken)(user);
    res.cookie("accessToken", token);
    res.sendStatus(200);
}
