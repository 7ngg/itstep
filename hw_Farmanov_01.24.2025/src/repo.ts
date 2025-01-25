import serializer from "./serializer";
import { Book } from "./types";

export async function create(book: Book): Promise<void> {
  let books = await serializer.Deserialize();
  books.push(book);
  await serializer.Serialize(books);
}

export function getAllBooks(): Promise<Book[]> {
  return serializer.Deserialize().catch((err) => {
    console.error(getAllBooks.name);
    throw err;
  });
}

export function getById(id: string): Promise<Book | undefined> {
  return serializer
    .Deserialize()
    .then((data) => data.find((v) => v.id === id))
    .catch((err) => {
      console.error(getById.name, err);
      throw err;
    });
}

export async function remove(id: string): Promise<void> {
  try {
    let books = await serializer.Deserialize();
    const updatedBooks = books.filter((book) => book.id !== id);
    await serializer.Serialize(updatedBooks);
  } catch (err) {
    console.error(remove.name, err);
    throw err;
  }
}
