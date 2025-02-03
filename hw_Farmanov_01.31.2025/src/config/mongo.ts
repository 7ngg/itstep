const host = process.env.MONGO_HOST;
const port = Number(process.env.MONGO_PORT);
const db = process.env.MONGO_DB;

export const Mongo = {
  host,
  port,
  db,
  connectionString: `mongodb://${host}:${port}/${db}`,
};
