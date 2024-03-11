using Newtonsoft.Json;
using ThreeApis.Models;

namespace ThreeApis.Services
{
    public class ForecastService(HttpClient client)
    {
        private readonly HttpClient _client = client;

        public async Task<Forecast> GetForecast(string city)
        {
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                       RequestUri = new Uri("https://open-weather13.p.rapidapi.com/city/Baku"),
                       Headers =
                       {
                           { "X-RapidAPI-Key", "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7" },
                           { "X-RapidAPI-Host", "open-weather13.p.rapidapi.com" },
                       },
            };
            using var response = await _client.SendAsync(request);

            response.EnsureSuccessStatusCode();
            var body = await response.Content.ReadAsStringAsync();
            var forecast = JsonConvert.DeserializeObject<Forecast>(body) ?? throw new ArgumentNullException(nameof(body));

            return forecast;
        }
    }
}
