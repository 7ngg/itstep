import { Request, Response, NextFunction } from "express";

export function globalExceptions(
  err: Error,
  req: Request,
  res: Response,
  next: NextFunction,
) {}
