"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.UserModel = exports.userSchema = void 0;
const mongoose_1 = require("mongoose");
exports.userSchema = new mongoose_1.Schema({
    username: { type: String, required: true, unique: true },
    password: { type: String, required: true },
    doj: { type: Date, default: new Date(), immutable: true },
});
exports.UserModel = (0, mongoose_1.model)("User", exports.userSchema);
