const url = 'http://www.omdbapi.com/?';

class OmdbService {
    constructor(key) {
        this.apiKey = key;
    }

    async getDataAsync(title, type) {
        try {
            const response = await fetch(`${url}apikey=${this.apiKey}&s=${title}&type=${type}`);
            return response.json();
        } catch (e) {
            throw e;
        }
    }
}

export default OmdbService;
