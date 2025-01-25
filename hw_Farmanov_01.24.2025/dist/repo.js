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
exports.create = create;
exports.getAllBooks = getAllBooks;
exports.getById = getById;
exports.remove = remove;
const serializer_1 = __importDefault(require("./serializer"));
function create(book) {
    return __awaiter(this, void 0, void 0, function* () {
        let books = yield serializer_1.default.Deserialize();
        books.push(book);
        yield serializer_1.default.Serialize(books);
    });
}
function getAllBooks() {
    return serializer_1.default.Deserialize().catch((err) => {
        console.error(getAllBooks.name);
        throw err;
    });
}
function getById(id) {
    return serializer_1.default
        .Deserialize()
        .then((data) => data.find((v) => v.id === id))
        .catch((err) => {
        console.error(getById.name, err);
        throw err;
    });
}
function remove(id) {
    return __awaiter(this, void 0, void 0, function* () {
        try {
            let books = yield serializer_1.default.Deserialize();
            const updatedBooks = books.filter((book) => book.id !== id);
            yield serializer_1.default.Serialize(updatedBooks);
        }
        catch (err) {
            console.error(remove.name, err);
            throw err;
        }
    });
}
