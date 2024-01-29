using Microsoft.EntityFrameworkCore;

namespace omdbApi.Services.Interfaces
{
    public interface IDataConnectionService
    {
        public DbContextOptions<T> Configure<T>(string connectionName) where T : DbContext;
    }
}
