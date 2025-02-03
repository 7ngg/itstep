import { InferSchemaType } from "mongoose";
import { userSchema } from "../models/user";
import jwt from "jsonwebtoken";
import { JwtSettings } from "../config/jwt";

export function generateToken(
  user: InferSchemaType<typeof userSchema>,
): string {
  const data = {
    username: user.username,
  };

  const secret = JwtSettings.secret;

  if (!secret) {
    throw new Error("jwt secret not found");
  }

  const token = jwt.sign(data, secret);

  return token;
}
