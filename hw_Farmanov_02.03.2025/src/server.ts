import { PrismaClient } from "@prisma/client";
import express from "express";
import { AuthorEndpoints } from "./endpoints/author";
import { BookEndpoints } from "./endpoints/books";

const prisma = new PrismaClient();
const app = express();

async function main() {
  app.use(express.json())

  const authorEndpoints = new AuthorEndpoints(prisma);
  const bookEndpoints = new BookEndpoints(prisma)

  app.get("/authors", authorEndpoints.getAll);
  app.get("/authors/:id", authorEndpoints.getById);
  app.post("/authors", authorEndpoints.create);
  app.delete("/authors/:id", authorEndpoints.delete);

  app.get("/books", bookEndpoints.getAll)
  app.get("/books/:id", bookEndpoints.getById)
  app.post("/books", bookEndpoints.create)
  app.delete("/books/:id", bookEndpoints.delete)

  app.listen(8080, () => console.log(`listening on 8080`));
}

main()
  .catch((err) => console.error(err))
  .finally(async () => await prisma.$disconnect());
