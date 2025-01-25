import express from "express";
import * as repo from "./repo";
import { Book, bookCreateDto, HttpStatusCode } from "./types";
import { randomUUID } from "node:crypto";

const app = express();
const port = 3000;

app.use(express.json());

app.use((req, _res, next) => {
  console.log(`[${new Date().toISOString()}] ${req.method} ${req.path}`);
  next();
});

app.get("/books", (_req, res) => {
  repo.getAllBooks().then((books) => res.send(books));
});

app.get("/books/:id", (req, res) => {
  const id: string = req.params.id;
  repo
    .getById(id)
    .then((book) => {
      if (book === undefined) {
        res.status(HttpStatusCode.NOTFOUND).send(`Book ${id} was not found`);
      }
      res.send(book);
    })
    .catch((err) => res.send(err));
});

app.post("/books", (req: express.Request, res) => {
  const data: bookCreateDto = req.body;

  if (!data.name || !data.author || !data.genre || !data.dop) {
    res.status(400).send({ message: "Missing required fields" });
  }

  const newBook: Book = {
    id: randomUUID(),
    ...data,
  };

  repo
    .create(newBook)
    .then(() => res.status(HttpStatusCode.CREATED).send(newBook))
    .catch((err) =>
      res
        .status(HttpStatusCode.INTERNAL_SERVER_ERROR)
        .send(`Error creating book: ${err}`),
    );
});

app.delete("/books/:id", (req, res) => {
  const id: string = req.params.id;

  repo
    .remove(id)
    .then(() => res.sendStatus(HttpStatusCode.NO_CONTENT))
    .catch((err) =>
      res
        .status(HttpStatusCode.INTERNAL_SERVER_ERROR)
        .send(`Error deleting ${id}: ${err}`),
    );
});

app.listen(port, () => {
  console.log(`--> application running at http://localhost:${port}`);
});
