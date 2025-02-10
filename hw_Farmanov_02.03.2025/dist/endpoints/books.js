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
Object.defineProperty(exports, "__esModule", { value: true });
exports.BookEndpoints = void 0;
class BookEndpoints {
    constructor(client) {
        this.client = client;
        this.getAll = (_req, res) => __awaiter(this, void 0, void 0, function* () {
            res.send(yield this.client.book.findMany({ include: { author: true } }));
        });
        this.getById = (req, res) => __awaiter(this, void 0, void 0, function* () {
            const id = req.params.id;
            const author = yield this.client.book.findUnique({
                where: { id },
                include: { author: true },
            });
            res.send(author);
        });
        this.create = (req, res) => __awaiter(this, void 0, void 0, function* () {
            const dto = req.body;
            let author = yield this.client.author.findUnique({
                where: { name: dto.author },
            });
            if (!author) {
                author = yield this.client.author.create({ data: { name: dto.author } });
            }
            yield this.client.book.create({
                data: {
                    name: dto.name,
                    authorId: author.id,
                },
            });
            res
                .status(201)
                .send(yield this.client.book.findUnique({ where: { name: dto.name } }));
        });
        this.delete = (req, res) => __awaiter(this, void 0, void 0, function* () {
            const id = req.params.id;
            yield this.client.book.delete({ where: { id } });
            res.sendStatus(204);
        });
    }
}
exports.BookEndpoints = BookEndpoints;
