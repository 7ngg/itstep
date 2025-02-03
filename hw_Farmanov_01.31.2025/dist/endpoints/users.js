"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.getAll = getAll;
exports.getById = getById;
exports.create = create;
exports.remove = remove;
const user_1 = require("../models/user");
const mongoose_1 = __importDefault(require("mongoose"));
async function getAll(_req, res) {
    const data = await user_1.userModel.find();
    res.status(200).json(data);
}
async function getById(req, res) {
    const id = req.params.id;
    if (!mongoose_1.default.isValidObjectId(id)) {
        res.status(400).json("Invalid object id");
        return;
    }
    const user = await user_1.userModel.findById(id);
    if (!user) {
        res.status(404).json("User does not exist");
        return;
    }
    res.status(200).send(user);
}
async function create(req, res) {
    const body = req.body;
    if (!body.username || !body.password) {
        res.status(400).send("Missing required data");
        return;
    }
    const newUser = {
        ...body,
        profile: {},
    };
    user_1.userModel.create(newUser);
    res.status(201).send(await user_1.userModel.findOne({ username: newUser.username }));
}
async function remove(req, res) {
    const id = req.params.id;
    if (!mongoose_1.default.isValidObjectId(id)) {
        res.status(400).json("Invalid object id");
        return;
    }
    user_1.userModel.findOneAndDelete({ _id: id });
    res.sendStatus(204);
}
