using System.Text;
using System.Text.Json;
using RabbitHw.Database;
using RabbitHw.RabbitMq;

namespace RabbitHw;

public class ExerciseCreationService(IServiceScopeFactory factory, Consumer consumer) : BackgroundService
{
    protected override Task ExecuteAsync(CancellationToken stoppingToken)
    {
        consumer.AddListener("tobe-created", async (_, args) =>
        {
            using var scope = factory.CreateScope();

            var ctx = scope.ServiceProvider.GetRequiredService<AppDbContext>();

            var body = args.Body.ToArray();
            var json = Encoding.UTF8.GetString(body);
            var exercise = JsonSerializer.Deserialize<Exercise>(json);

            await ctx.Exercises.AddAsync(exercise!, stoppingToken);
            await ctx.SaveChangesAsync(stoppingToken);
        });

        return Task.CompletedTask;
    }
}