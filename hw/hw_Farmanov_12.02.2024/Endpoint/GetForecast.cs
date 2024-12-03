using System.Net;
using FastEndpoints;
using Homework.Services.Interfaces;

namespace Homework.Endpoints;

public class GetForecast(IForecastService forecastService) : EndpointWithoutRequest
{
    public override void Configure()
    {
        Verbs(Http.GET);
        Routes("api/forecast/{city}");
        AllowAnonymous();
    }

    public override async Task HandleAsync(CancellationToken ct)
    {
        var city = Route<string>("city");

        if (city is null)
        {
            await SendNotFoundAsync(ct);
            return;
        }

        var result = await forecastService.GetForecast(city);

        result.Match(
            async succ => await SendOkAsync(succ, ct),
            async () => await SendErrorsAsync((int)HttpStatusCode.BadRequest, ct));
    }
}