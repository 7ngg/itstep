namespace RabbitHw.Database;

public class Exercise
{
    public int Id { get; init; }

    public required string Topic { get; set; }
    public required string Statement { get; set; }

    public DateTime CreatedAt { get; init; } = DateTime.UtcNow;
    public DateTime? Deadline { get; set; }
}