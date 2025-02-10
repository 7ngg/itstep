export type authorDto = {
  name: string;
};

export type authorCreateDto = authorDto;

export type bookCreateDto = {
  name: string;
  author: string;
};
