using Google.Protobuf.WellKnownTypes;
using Grpc.Core;

namespace Server;

internal record WeatherForecast(DateOnly Date, int TemperatureC, string? Summary)
{
    public int TemperatureF => 32 + (int)(TemperatureC / 0.5556);
}

internal static class Ext
{
    internal static ForecastReply ToResponse(this WeatherForecast wf) => new ForecastReply
    {
        Date = wf.Date.ToString(), TemperatureC = wf.TemperatureC, TemperatureF = wf.TemperatureF, Summary = wf.Summary
    };
}

public class ForecastService : Forecast.ForecastBase
{
    public override async Task Get(Empty request, IServerStreamWriter<ForecastReply> responseStream,
        ServerCallContext context)
    {
        var summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };

        var forecast = Enumerable.Range(1, 5).Select(index =>
                new WeatherForecast
                (
                    DateOnly.FromDateTime(DateTime.Now.AddDays(index)),
                    Random.Shared.Next(-20, 55),
                    summaries[Random.Shared.Next(summaries.Length)]
                ))
            .ToArray();

        foreach (var f in forecast) await responseStream.WriteAsync(f.ToResponse());
    }
}