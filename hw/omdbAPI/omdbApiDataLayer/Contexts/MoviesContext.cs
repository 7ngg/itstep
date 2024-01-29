using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using omdbApiDataLayer.Models;

namespace omdbApiDataLayer.Contexts
{
    public class MoviesContext : DbContext
    {
        public MoviesContext() { }
        public MoviesContext(DbContextOptions<MoviesContext> opts) : base(opts) { }

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            ConfigurationBuilder builder = new();
            builder.AddJsonFile("app-settings.json");
            var config = builder.Build();
            var connectionString = config.GetConnectionString("Home");
            optionsBuilder.UseSqlServer(connectionString);
        }

        public DbSet<MovieModel> Movies { get; set; }
    }
}
