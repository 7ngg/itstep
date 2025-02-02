import mongoose from "mongoose";
import { mongo, server } from "./config/config";
import express from "express";
import { userCreateDto, UserModel } from "./entities/user";
import { logRequest } from "./middlewares/logging";
import { routeNotFound } from "./middlewares/routeNotFound";
import { exit } from "node:process";

const app = express();

async function Main() {
  app.use(express.json());
  app.use(logRequest);

  try {
    await mongoose.connect(mongo.connectionString);
    console.log("--> Connected");
  } catch (err) {
    console.error("Error connecting mongo:", err);
    exit(-1);
  }

  app.get("/users", (_req, res) => {
    UserModel.find().then((users) => res.status(200).json(users));
  });

  app.get("/users/:id", async (req, res) => {
    const id: string = req.params.id;
    const user = await UserModel.findById(id);

    if (!user) {
      res.sendStatus(404);
      return;
    }

    res.status(200).send(user);
  });

  app.post("/users", async (req: express.Request<userCreateDto>, res) => {
    const body: userCreateDto = req.body;

    if (!body.username || !body.password) {
      res.status(400).json("Missing required field");
      return;
    }

    const newUser = {
      ...body,
      doj: new Date(),
    };

    try {
      UserModel.create(newUser);
      res
        .status(201)
        .send(await UserModel.findOne({ username: newUser.username }));
    } catch (err) {
      res.status(500).send(err);
      return;
    }
  });

  app.delete("/users/:id", async (req, res) => {
    const id: string = req.params.id;

    if (!mongoose.isValidObjectId(id)) {
      res.status(400).send("Invalid id format");
      return;
    }

    await UserModel.findOneAndDelete({ _id: id });
    res.sendStatus(204);
  })

  app.use(routeNotFound);

  app.listen(server.port, () => {
    console.warn(`--> Server running on http://${server.host}:${server.port}`);
  });
}

Main();
