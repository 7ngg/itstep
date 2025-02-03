"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.profileModel = exports.profileSchema = void 0;
const mongoose_1 = __importDefault(require("mongoose"));
exports.profileSchema = new mongoose_1.default.Schema({
    firstName: { type: String },
    lastName: { type: String },
    age: { type: Number },
});
exports.profileModel = mongoose_1.default.model("profile", exports.profileSchema);
