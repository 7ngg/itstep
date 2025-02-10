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
exports.AuthorEndpoints = void 0;
class AuthorEndpoints {
    constructor(client) {
        this.client = client;
        this.getAll = (_req, res) => __awaiter(this, void 0, void 0, function* () {
            res.send(yield this.client.author.findMany());
        });
        this.getById = (req, res) => __awaiter(this, void 0, void 0, function* () {
            const id = Number(req.params.id);
            res.send(yield this.client.author.findUnique({ where: { id } }));
        });
        this.create = (req, res) => __awaiter(this, void 0, void 0, function* () {
            const dto = req.body;
            yield this.client.author.create({ data: dto });
            res
                .status(201)
                .send(yield this.client.author.findUnique({ where: { name: dto.name } }));
        });
        this.delete = (req, res) => __awaiter(this, void 0, void 0, function* () {
            const id = Number(req.params.id);
            yield this.client.author.delete({ where: { id } });
            res.sendStatus(204);
        });
    }
}
exports.AuthorEndpoints = AuthorEndpoints;
