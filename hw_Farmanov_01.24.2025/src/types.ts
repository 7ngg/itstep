import { UUID } from "node:crypto";

export interface Book {
  id: UUID,
  name: string,
  author: string,
  genre: string,
  dop: Date
}

export type bookCreateDto = Omit<Book, "id">;

export enum HttpStatusCode {
  OK = 200,
  CREATED = 201,
  NO_CONTENT = 204,
  BAD_REQUEST = 400,
  NOTFOUND = 404,
  INTERNAL_SERVER_ERROR = 500,
}
