using System.Text;
using System.Text.Json;
using FastEndpoints;
using RabbitHw.Database;
using RabbitHw.RabbitMq;

namespace RabbitHw.Endpoints;

public record Request(string Topic, string Statement, int DaysToComplete);

public class Create(AppDbContext context, Producer producer) : Endpoint<Request, Exercise>
{
    public override void Configure()
    {
        Verbs(Http.POST);
        Routes("exercises");
        AllowAnonymous();
    }

    public override async Task HandleAsync(Request req, CancellationToken ct)
    {
        var exercise = new Exercise
        {
            Topic = req.Topic,
            Statement = req.Statement,
            Deadline = req.DaysToComplete == 0 ? null : DateTime.Now.AddDays(req.DaysToComplete)
        };

        var json = JsonSerializer.Serialize(exercise);
        var bytes = Encoding.UTF8.GetBytes(json);

        await producer.Send("tobe-created", bytes);

        await SendCreatedAtAsync<Create>(routeValues: HttpContext.Request.RouteValues, responseBody: exercise,
            cancellation: ct);
    }
}