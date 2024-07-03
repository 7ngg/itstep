export type Movie = {
  Title: string;
  Year: number;
  Schedule: Date[];
  Poster: string;
};

class OmdbService {
  url: string = "http://www.omdbapi.com/?";
  apiKey: string;

  constructor(key: string) {
    this.apiKey = key;
  }

  async getData(title: string, type: string, page = 1): Promise<Movie[]> {
    try {
      const response = await fetch(
        `${this.url}apikey=${this.apiKey}&s=${title}&type=${type}&page=${page}`,
      );

      if (!response.ok) {
        throw new Error(`HTTP error! status: ${response.status}`);
      }

      const data = await response.json();

      if (!data.Search || !Array.isArray(data.Search)) {
        throw new Error("Invalid response format");
      }

      const mvs: Movie[] = data.Search.map((mv: any) => ({
        Title: mv.Title,
        Year: mv.Year,
        Schedule: [new Date(), new Date(), new Date()],
        Poster: mv.Poster,
      }));

      return mvs;
    } catch (e) {
      console.error("Error fetching data:", e);
      throw e;
    }
  }
}

export default OmdbService;
