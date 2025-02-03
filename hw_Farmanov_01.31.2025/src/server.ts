require("dotenv").config();

import express from "express";
import { Server } from "./config/server";

import authRouter from "./routes/auth";
import usersRouter from "./routes/users";
import mongoose from "mongoose";
import { Mongo } from "./config/mongo";

mongoose
  .connect(Mongo.connectionString)
  .then(() => console.log(`--> Connected to ${Mongo.db}`))
  .catch((err) => {
    console.error("Error connecting mongo", err);
    process.exit(-1);
  });

const app = express();

app.use(express.json());

app.get("/api/healthcheck", (_req, res) => {
  res.json({ hello: "world" });
});

app.use("/api/auth", authRouter);
app.use("/api/users", usersRouter);

app.listen(Server.port, () => {
  console.info(`--> Running on http://${Server.host}:${Server.port}`);
});
