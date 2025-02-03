import mongoose from "mongoose";

export const profileSchema = new mongoose.Schema({
  firstName: { type: String },
  lastName: { type: String },
  age: { type: Number },
});

export const profileModel = mongoose.model("profile", profileSchema);
