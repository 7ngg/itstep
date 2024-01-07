using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

var builder = new ConfigurationBuilder();
builder.AddJsonFile("app-settings.json");
var config = builder.Build();
var connectionString =  config.GetConnectionString("default");

string scalarQuery = "select COUNT(*) from Cars";
string nonQueryQuery = "delete from ProductList where price < 30000";

using SqlConnection connection = new(connectionString);
using SqlCommand scalarCommand = new(scalarQuery, connection);
using SqlCommand nonQueryCommand = new(nonQueryQuery, connection);

try
{
    connection.Open();
    System.Console.WriteLine($"Execute scalar: {scalarCommand.ExecuteScalar()}");           // Вернет первую строку первого столбца
    System.Console.WriteLine($"Execute non query: {nonQueryCommand.ExecuteNonQuery()}");    // Вернет количество затронутых строк
}
catch (System.Exception e)
{    
    System.Console.WriteLine(e.Message);
}


Console.ReadLine();
