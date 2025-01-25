"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || (function () {
    var ownKeys = function(o) {
        ownKeys = Object.getOwnPropertyNames || function (o) {
            var ar = [];
            for (var k in o) if (Object.prototype.hasOwnProperty.call(o, k)) ar[ar.length] = k;
            return ar;
        };
        return ownKeys(o);
    };
    return function (mod) {
        if (mod && mod.__esModule) return mod;
        var result = {};
        if (mod != null) for (var k = ownKeys(mod), i = 0; i < k.length; i++) if (k[i] !== "default") __createBinding(result, mod, k[i]);
        __setModuleDefault(result, mod);
        return result;
    };
})();
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const express_1 = __importDefault(require("express"));
const repo = __importStar(require("./repo"));
const types_1 = require("./types");
const node_crypto_1 = require("node:crypto");
const app = (0, express_1.default)();
const port = 3000;
app.use(express_1.default.json());
app.use((req, _res, next) => {
    console.log(`[${new Date().toISOString()}] ${req.hostname} ${req.method} ${req.path}`);
    next();
});
app.get("/books", (_req, res) => {
    repo.getAllBooks().then((books) => res.send(books));
});
app.get("/books/:id", (req, res) => {
    const id = req.params.id;
    repo
        .getById(id)
        .then((book) => {
        if (book === undefined) {
            res.status(types_1.HttpStatusCode.NOTFOUND).send(`Book ${id} was not found`);
        }
        res.send(book);
    })
        .catch((err) => res.send(err));
});
app.post("/books", (req, res) => {
    const data = req.body;
    if (!data.name || !data.author || !data.genre || !data.dop) {
        res.status(400).send({ message: "Missing required fields" });
    }
    const newBook = Object.assign({ id: (0, node_crypto_1.randomUUID)() }, data);
    repo
        .create(newBook)
        .then(() => res.status(types_1.HttpStatusCode.CREATED).send(newBook))
        .catch((err) => res
        .status(types_1.HttpStatusCode.INTERNAL_SERVER_ERROR)
        .send(`Error creating book: ${err}`));
});
app.delete("/books/:id", (req, res) => {
    const id = req.params.id;
    repo
        .remove(id)
        .then(() => res.sendStatus(types_1.HttpStatusCode.NO_CONTENT))
        .catch((err) => res
        .status(types_1.HttpStatusCode.INTERNAL_SERVER_ERROR)
        .send(`Error deleting ${id}: ${err}`));
});
app.listen(port, () => {
    console.log(`--> application running at http://localhost:${port}`);
});
