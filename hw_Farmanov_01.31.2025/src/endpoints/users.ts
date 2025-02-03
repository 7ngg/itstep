import { Request, Response } from "express";
import { userDto, userModel, userSchema } from "../models/user";
import mongoose, { InferSchemaType } from "mongoose";

export async function getAll(_req: Request, res: Response) {
  const data = await userModel.find();

  res.status(200).json(data);
}

export async function getById(req: Request, res: Response) {
  const id = req.params.id;

  if (!mongoose.isValidObjectId(id)) {
    res.status(400).json("Invalid object id");
    return;
  }

  const user = await userModel.findById(id);

  if (!user) {
    res.status(404).json("User does not exist");
    return;
  }

  res.status(200).send(user);
}

export async function create(req: Request, res: Response) {
  const body: userDto = req.body;

  if (!body.username || !body.password) {
    res.status(400).send("Missing required data");
    return;
  }

  const newUser: InferSchemaType<typeof userSchema> = {
    ...body,
    profile: {},
  };

  userModel.create(newUser);

  res.status(201).send(await userModel.findOne({ username: newUser.username }));
}

export async function remove(req: Request, res: Response) {
  const id = req.params.id;

  if (!mongoose.isValidObjectId(id)) {
    res.status(400).json("Invalid object id");
    return;
  }

  userModel.findOneAndDelete({ _id: id });

  res.sendStatus(204);
}
