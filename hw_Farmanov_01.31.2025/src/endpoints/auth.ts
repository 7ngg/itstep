import { Request, Response } from "express";
import { loginDto, registerDto, userModel } from "../models/user";
import bcrypt from "bcrypt";
import { profileModel } from "../models/profile";
import { generateToken } from "../helpers/tokenService";

export async function register(req: Request, res: Response) {
  const body: registerDto = req.body;

  if (!body.username || !body.password) {
    res.status(400).send("Missing required fields");
  }

  const model = await profileModel.create({
    firstName: body.firstName,
    lastName: body.lastName,
    age: body.age,
  });

  await userModel.create({
    username: body.username,
    password: await bcrypt.hash(body.password, 10),
    profile: model,
  });

  res.status(201).send(await userModel.findOne({ username: body.username }));
}

export async function login(req: Request, res: Response) {
  const body: loginDto = req.body;

  if (!body.username || !body.password) {
    res.status(400).send("Missing required fields");
  }

  const user = await userModel.findOne({ username: body.username });

  if (!user) {
    res.status(401).send("User does not exist");
    return;
  }

  if (!(await bcrypt.compare(body.password, user.password))) {
    res.status(401).send("Invalid credentials");
    return;
  }

  const token: string = generateToken(user);
  res.cookie("accessToken", token);

  res.sendStatus(200);
}
