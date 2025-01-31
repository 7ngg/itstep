import dotenv from "dotenv";

dotenv.config();

const serverHost = process.env.HOST || "localhost";
const serverPort = process.env.PORT ? Number(process.env.PORT) : 3000;

export const server = {
  host: serverHost,
  port: serverPort,
};

const mongoUrl = process.env.MONGO_URL;
const mongoTable = process.env.MONGO_TABLE;

export const mongo = {
  url: mongoUrl,
  table: mongoTable,
  connectionString: `mongodb://${mongoUrl}/${mongoTable}`,
};
