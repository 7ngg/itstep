const header = process.env.JWT_HEADER;
const secret = process.env.JWT_SECRET;

export const JwtSettings = {
  header,
  secret,
};
