"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
const promises_1 = require("fs/promises");
class BookSerializer {
    constructor() {
        this.Deserialize = () => {
            return (0, promises_1.readFile)("./books.json", { encoding: "utf8" })
                .then((data) => JSON.parse(data))
                .catch((err) => {
                console.error(err);
                throw err;
            });
        };
        this.Serialize = (books) => {
            const json = JSON.stringify(books, null, 2);
            return (0, promises_1.writeFile)("./books.json", json)
                .then(() => console.log("Serialization successful"))
                .catch((err) => {
                console.error(err);
                throw err;
            });
        };
    }
}
exports.default = new BookSerializer();
