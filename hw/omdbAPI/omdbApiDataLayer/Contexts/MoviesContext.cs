using Microsoft.EntityFrameworkCore;
using omdbApiDataLayer.Models;

namespace omdbApiDataLayer.Contexts
{
    public class MoviesContext : DbContext
    {
        public MoviesContext() { }
        public MoviesContext(DbContextOptions<MoviesContext> opts) : base(opts) { }

        public DbSet<MovieModel> Movies { get; set; }
    }
}
