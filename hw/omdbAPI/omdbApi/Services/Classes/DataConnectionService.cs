using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;
using omdbApi.Services.Interfaces;

namespace omdbApi.Services.Classes
{
    public class DataConnectionService : IDataConnectionService
    {
        private readonly IConfigurationBuilder _builder;

        public DataConnectionService(IConfigurationBuilder builder)
        {
            _builder = builder;
        }

        public DbContextOptions<T> ConfigureOptions<T>(string connectionName) where T : DbContext
        {
            _builder.AddJsonFile("app-settings.json");
            var config = _builder.Build();
            var connectionString = config.GetConnectionString(connectionName);
            var optionsBuilder = new DbContextOptionsBuilder<T>();
            optionsBuilder.UseSqlServer(connectionString);

            return optionsBuilder.Options;
        }
    }
}
