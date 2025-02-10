import { PrismaClient } from "@prisma/client";
import { Request, Response } from "express";
import { authorCreateDto } from "../types";

export class AuthorEndpoints {
  constructor(private readonly client: PrismaClient) {}

  getAll = async (_req: Request, res: Response) => {
    res.send(await this.client.author.findMany());
  };

  getById = async (req: Request, res: Response) => {
    const id: number = Number(req.params.id);

    res.send(await this.client.author.findUnique({ where: { id } }));
  };

  create = async (req: Request, res: Response) => {
    const dto: authorCreateDto = req.body;

    await this.client.author.create({ data: dto });

    res
      .status(201)
      .send(await this.client.author.findUnique({ where: { name: dto.name } }));
  };

  delete = async (req: Request, res: Response) => {
    const id: number = Number(req.params.id);

    await this.client.author.delete({ where: { id } });

    res.sendStatus(204);
  };
}
