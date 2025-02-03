import mongoose from "mongoose";
import { profileSchema } from "./profile";

export type userDto = {
  username: string;
  password: string;
};

export type loginDto = userDto;

export type registerDto = {
  username: string;
  password: string;
  firstName: string;
  lastName: string;
  age: Number;
};

export const userSchema = new mongoose.Schema({
  username: { type: String, required: true, unique: true },
  password: { type: String, required: true },
  profile: { type: profileSchema },
});

export const userModel = mongoose.model("user", userSchema);
