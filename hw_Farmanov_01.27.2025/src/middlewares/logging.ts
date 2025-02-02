import { Request, Response, NextFunction } from "express";

export function logRequest(req: Request, _res: Response, next: NextFunction) {
  console.log(
    `[${new Date().toISOString()}] ${req.method}\t ${req.path}\t ${req.socket.remoteAddress}`,
  );
  next();
}
