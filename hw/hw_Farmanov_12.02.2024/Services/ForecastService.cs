using Homework.Data;
using Homework.Services.Interfaces;
using LanguageExt;
using Newtonsoft.Json;

namespace Homework.Services;

public class ForecastService(IConfiguration configuration, HttpClient httpClient) : IForecastService
{
    private readonly string _apiKey = configuration["OpenWeatherMap:ApiKey"]!;

    public async Task<Option<GetForecastResponse>> GetForecast(string city)
    {
        var response = await httpClient.GetAsync($"data/2.5/weather?q={city}&appid={_apiKey}");

        if (!response.IsSuccessStatusCode)
        {
            return new Option<GetForecastResponse>();
        }

        var obj = JsonConvert.DeserializeObject<GetForecastResponse>(await response.Content.ReadAsStringAsync());

        return obj;
    }
}
