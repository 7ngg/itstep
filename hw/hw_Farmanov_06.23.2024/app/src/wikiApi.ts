import axios from "axios";

export type wikiResponse = {
  data: string;
  message: string;
};

export async function getSummary(
  query: string,
  sentences: number,
): Promise<wikiResponse> {
  const options = {
    method: "GET",
    url: "https://wikipedia-api1.p.rapidapi.com/get_summary",
    headers: {
      "x-rapidapi-key": "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7",
      "x-rapidapi-host": "wikipedia-api1.p.rapidapi.com",
    },
    params: {
      q: query,
      lang: "ru",
      sentences: sentences,
    },
  };

  try {
    const response = await axios.request(options);

    if (response.status !== 200) {
      return {
        data: "",
        message: `Error: ${response.status} ${response.statusText}`,
      };
    }

    const data: wikiResponse = {
      data: response.data.data,
      message: response.data.message,
    };

    console.log(data);

    return response.data as wikiResponse;
  } catch (e) {
    return {
      data: "",
      message: `Fetch error: ${e}`,
    };
  }
}
