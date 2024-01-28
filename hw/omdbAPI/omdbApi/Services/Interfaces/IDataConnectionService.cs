using Microsoft.EntityFrameworkCore;

namespace omdbApi.Services.Interfaces
{
    public interface IDataConnectionService
    {
        public DbContextOptions<T> ConfigureOptions<T>(string connectionName) where T : DbContext;
    }
}
