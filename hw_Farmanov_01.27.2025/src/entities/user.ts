import { model, ObjectId, Schema } from "mongoose";

export interface User {
  _id: ObjectId;
  username: string;
  password: string;
  doj: Date;
}

export type userCreateDto = Omit<User, "_id" | "doj">;

export const userSchema = new Schema({
  _id: { type: String, required: true, unique: true },
  username: { type: String, required: true, unique: true },
  password: { type: String, required: true },
  doj: { type: Date, default: new Date(), immutable: true },
});

export const UserModel = model("User", userSchema);
