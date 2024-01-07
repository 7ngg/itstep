using System.Data.SqlClient;
using Microsoft.Extensions.Configuration;

var builder = new ConfigurationBuilder();
builder.AddJsonFile("app-settings.json");
var config = builder.Build();
var connectionString =  config.GetConnectionString("step");

string scalarQuery = "select * from People";
string noQueryQuery = "insert into People(Name, Surname, Age) values('Name1', 'Surname1', 37)";

using SqlConnection connection = new(connectionString);
using SqlCommand cmd = new(scalarQuery, connection);

try
{
    connection.Open();
    System.Console.WriteLine(cmd.ExecuteScalar());;
}
catch (System.Exception e)
{    
    System.Console.WriteLine(e.Message);
}


Console.ReadLine();
