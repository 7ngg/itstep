using Microsoft.EntityFrameworkCore;
using Server.Data.Models;

namespace Server.Data;

public class AppDbContext(DbContextOptions<AppDbContext> opts) : DbContext(opts)
{
    public DbSet<User> Users { get; set; }
}
