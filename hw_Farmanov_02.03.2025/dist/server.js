"use strict";
var __awaiter = (this && this.__awaiter) || function (thisArg, _arguments, P, generator) {
    function adopt(value) { return value instanceof P ? value : new P(function (resolve) { resolve(value); }); }
    return new (P || (P = Promise))(function (resolve, reject) {
        function fulfilled(value) { try { step(generator.next(value)); } catch (e) { reject(e); } }
        function rejected(value) { try { step(generator["throw"](value)); } catch (e) { reject(e); } }
        function step(result) { result.done ? resolve(result.value) : adopt(result.value).then(fulfilled, rejected); }
        step((generator = generator.apply(thisArg, _arguments || [])).next());
    });
};
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const client_1 = require("@prisma/client");
const express_1 = __importDefault(require("express"));
const author_1 = require("./endpoints/author");
const books_1 = require("./endpoints/books");
const prisma = new client_1.PrismaClient();
const app = (0, express_1.default)();
function main() {
    return __awaiter(this, void 0, void 0, function* () {
        app.use(express_1.default.json());
        const authorEndpoints = new author_1.AuthorEndpoints(prisma);
        const bookEndpoints = new books_1.BookEndpoints(prisma);
        app.get("/authors", authorEndpoints.getAll);
        app.get("/authors/:id", authorEndpoints.getById);
        app.post("/authors", authorEndpoints.create);
        app.delete("/authors/:id", authorEndpoints.delete);
        app.get("/books", bookEndpoints.getAll);
        app.get("/books/:id", bookEndpoints.getById);
        app.post("/books", bookEndpoints.create);
        app.delete("/books/:id", bookEndpoints.delete);
        app.listen(8080, () => console.log(`listening on 8080`));
    });
}
main()
    .catch((err) => console.error(err))
    .finally(() => __awaiter(void 0, void 0, void 0, function* () { return yield prisma.$disconnect(); }));
