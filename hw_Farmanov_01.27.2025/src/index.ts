import mongoose from "mongoose";
import { mongo, server } from "./config/config";
import express from "express";
import { UserModel } from "./entities/user";
import { logRequest } from "./middlewares/logging";
import { routeNotFound } from "./middlewares/routeNofDound";

const app = express();

async function Main() {
  app.use(express.json());
  app.use(logRequest);

  try {
    await mongoose.connect(mongo.connectionString);
    console.log("--> Connected");
  } catch (err) {
    console.error("Error connecting mongo:", err);
  }

  app.get("/users", (_req, res) => {
    UserModel.find().then((users) => res.status(200).json(users));
  });

  app.use(routeNotFound);

  app.listen(server.port, () => {
    console.warn(`--> Server running on http://${server.host}:${server.port}`);
  });
}

Main();
