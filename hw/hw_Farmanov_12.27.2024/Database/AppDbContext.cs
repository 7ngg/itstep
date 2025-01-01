using Microsoft.EntityFrameworkCore;

namespace RabbitHw.Database;

public class AppDbContext(DbContextOptions<AppDbContext> opts) : DbContext(opts)
{
    public DbSet<Exercise> Exercises { get; set; }
}