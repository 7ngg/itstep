export type City = {
  name: string;
  country: string;
  population: string;
  lat: number;
  lng: number;
};

export class CityInfoService {
  async GetInfo(query: string): Promise<City> {
    const url = `https://citydatabox1.p.rapidapi.com/city/${query}`;
    const options = {
      method: "GET",
      headers: {
        "x-rapidapi-key": "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7",
        "x-rapidapi-host": "citydatabox1.p.rapidapi.com",
      },
    };

    try {
      const response = await fetch(url, options);
      const result = await response.json();

      const city: City = {
        name: result.city,
        country: result.country,
        population: result.population,
        lat: result.lat,
        lng: result.lng,
      } 

      return city;
    } catch (error) {
      throw error;
    }
  }
}
