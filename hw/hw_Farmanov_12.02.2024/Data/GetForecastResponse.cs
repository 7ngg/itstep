using Newtonsoft.Json;

namespace Homework.Data;

public record GetForecastResponse(
    [JsonProperty("name")] string City,
    [JsonProperty("main")] Temperature Temperature);

public record Temperature
{
    [JsonProperty("temp")]
    private double _kelvin;

    public double Kelvin => _kelvin;

    public double Celsius => _kelvin - 273.15;
}