import { model, Schema } from "mongoose";

export type userCreateDto = {
  username: string;
  password: string;
};

export const userSchema = new Schema({
  username: { type: String, required: true, unique: true },
  password: { type: String, required: true },
  doj: { type: Date, default: new Date(), immutable: true },
});

export const UserModel = model("User", userSchema);
