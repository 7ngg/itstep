const url = "http://www.omdbapi.com/?";

class OmdbService {
  constructor(key) {
    this.apiKey = key;
  }

  async getDataAsync(title, type, page = 1) {
    try {
      const response = await fetch(
        `${url}apikey=${this.apiKey}&s=${title}&type=${type}&page=${page}`
      );
      return response.json();
    } catch (e) {
      throw e;
    }
  }

  async getDataByIdAsync(id) {
    try {
      const response = await fetch(`${url}apikey=${this.apiKey}&i=${id}`);
      return response.json();
    } catch (e) {
      throw e;
    }
  }
}

export default OmdbService;
