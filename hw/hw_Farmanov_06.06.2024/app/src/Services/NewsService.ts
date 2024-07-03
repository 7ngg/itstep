export type BlogInfo = {
  Title: string;
  Url: string;
  Thumbnail: string;
  Date: Date;
};

export class NewsService {
  async GetNews(query: string): Promise<BlogInfo[]> {
    const url: string = `https://news-api14.p.rapidapi.com/v2/search/articles?query=${query}&language=en`;
    const options = {
      method: "GET",
      headers: {
        "x-rapidapi-key": "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7",
        "x-rapidapi-host": "news-api14.p.rapidapi.com",
      },
    };

    try {
      const response = await fetch(url, options);
      const result = await response.json();

      if (!result.data) {
        throw new Error("Invalid query");
      }

      let news: BlogInfo[] = [];

      result.data.forEach((n: any) =>
        news.push({
          Title: n.title,
          Url: n.url,
          Thumbnail: n.thumbnail,
          Date: n.date,
        }),
      );

      return news;
    } catch (e) {
      throw e;
    }
  }
}
