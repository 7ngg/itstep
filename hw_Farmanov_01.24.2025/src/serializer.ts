import { readFile, writeFile } from "fs/promises";
import { Book } from "./types";

class BookSerializer {
  Deserialize = (): Promise<Book[]> => {
    return readFile("./books.json", { encoding: "utf8" })
      .then((data) => JSON.parse(data) as Book[])
      .catch((err) => {
        console.error(err);
        throw err;
      });
  };

  Serialize = (books: Book[]): Promise<void> => {
    const json: string = JSON.stringify(books, null, 2);
    return writeFile("./books.json", json)
      .then(() => console.log("Serialization successful"))
      .catch((err) => {
        console.error(err);
        throw err;
      });
  };
}

export default new BookSerializer();
