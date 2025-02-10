import { PrismaClient } from "@prisma/client";
import { Request, Response } from "express";
import { bookCreateDto } from "../types";

export class BookEndpoints {
  constructor(private readonly client: PrismaClient) {}

  getAll = async (_req: Request, res: Response) => {
    res.send(await this.client.book.findMany({ include: { author: true } }));
  };

  getById = async (req: Request, res: Response) => {
    const id: string = req.params.id;

    const author = await this.client.book.findUnique({
      where: { id },
      include: { author: true },
    });

    res.send(author);
  };

  create = async (req: Request, res: Response) => {
    const dto: bookCreateDto = req.body;

    let author = await this.client.author.findUnique({
      where: { name: dto.author },
    });

    if (!author) {
      author = await this.client.author.create({ data: { name: dto.author } });
    }

    await this.client.book.create({
      data: {
        name: dto.name,
        authorId: author!.id,
      },
    });

    res
      .status(201)
      .send(await this.client.book.findUnique({ where: { name: dto.name } }));
  };

  delete = async (req: Request, res: Response) => {
    const id: string = req.params.id;

    await this.client.book.delete({ where: { id } });

    res.sendStatus(204);
  };
}
