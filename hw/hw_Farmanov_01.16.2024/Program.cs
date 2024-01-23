using hw_Farmanov_01._16._2024;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Configuration;


DbContextOptions<NorthwindContext> configureOptions(string dbName)
{
    var builder = new ConfigurationBuilder();
    builder.AddJsonFile("app-settings.json");

    var config = builder.Build();
    var connectionString = config.GetConnectionString(dbName);
    var dbContextOptionsBuilder = new DbContextOptionsBuilder<NorthwindContext>();

    return dbContextOptionsBuilder.UseSqlServer(connectionString).Options;
}


var options = configureOptions("Home");
using NorthwindContext context = new(options);
//var tables = context.GetType().GetProperties();
var tables = context.Model.GetEntityTypes().Select(t => t.ClrType).ToArray();

for (int i = 0; i < tables.Length; i++)
{
    System.Console.WriteLine($"{i + 1}. {tables[i].Name}");
}
Console.Write("Select table: ");
int choice = Convert.ToInt32(Console.ReadLine());

var entityType = tables[choice - 1];
