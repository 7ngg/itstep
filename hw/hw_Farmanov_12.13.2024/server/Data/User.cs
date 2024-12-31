namespace Server.Data.Models;

public class User
{
    public Guid Id { get; set; } = Guid.NewGuid();

    public required string Email { get; set; }

    public required string Firstname { get; set; }
    public required string Lastname { get; set; }
    public required int Age { get; set; }

    public DateTime RegistryDate { get; set; } = DateTime.UtcNow;
}
