using FastEndpoints;
using Microsoft.EntityFrameworkCore;
using RabbitHw.Database;

namespace RabbitHw.Endpoints.Exercises;

public class GetAll(AppDbContext context) : EndpointWithoutRequest
{
    public override void Configure()
    {
        Verbs(Http.GET);
        Routes("exercises");
        AllowAnonymous();
    }

    public override async Task HandleAsync(CancellationToken ct)
    {
        var exercises = await context.Exercises.ToArrayAsync(ct);

        await SendOkAsync(exercises, ct);
    }
}