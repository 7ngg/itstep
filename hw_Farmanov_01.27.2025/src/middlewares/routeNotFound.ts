import { Request, Response, NextFunction } from "express";

export function routeNotFound(_req: Request, res: Response, _next: NextFunction) {
  res.status(404).json({ error: { message: "Route does not exist" } });
}
