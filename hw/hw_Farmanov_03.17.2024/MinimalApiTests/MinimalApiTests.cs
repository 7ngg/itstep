using FluentAssertions;
using Microsoft.EntityFrameworkCore;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using MinimalApi.Data.Contexts;
using MinimalApiTests.Services;
using Newtonsoft.Json;
using RestSharp;

namespace MinimalApiTests;

internal class TrimmedEmployee
{
    public int EmployeeId { get; set; }
    public string LastName { get; set; }
    public string FirstName { get; set; }
    public string Address { get; set; }
    public string City { get; set; }
    public DateTime BirthDate { get; set; }
    public DateTime HireDat { get; set; }
}

[TestClass]
public class GetMethodTests
{
    private async Task<NorthwindContext> GetDbContext()
    {
        var generator = new EntityGenerator();

        var opts = new DbContextOptionsBuilder<NorthwindContext>()
            .UseInMemoryDatabase(databaseName: Guid.NewGuid().ToString())
            .Options;

        var context = new NorthwindContext(opts);

        context.Database.EnsureCreated();

        if (!await context.Employees.AnyAsync())
        {
            var fakeEmployees = generator.EmployeeFaker.Generate(5);
            context.Employees.AddRange(fakeEmployees);
        }

        if (!await context.Products.AnyAsync())
        {
            var fakeProducts = generator.ProductFaker.Generate(10);
            context.Products.AddRange(fakeProducts);
        }

        await context.SaveChangesAsync();
        return context;
    }

    [TestMethod]
    public async Task MinimalApi_GetEmployees_ReturnsEmployeesList()
    {
        // Arrange
        var httpClient = new HttpClient() { BaseAddress = new("https://localhost:7029/") };


        // Act
        var response = await httpClient.GetStringAsync("getemployees");
        var result = JsonConvert.DeserializeObject<List<TrimmedEmployee>>(response);


        // Assert
        result.Should().NotBeNull();
        result.Should().BeOfType<List<TrimmedEmployee>>();
    }

    [TestMethod]
    public async Task MinimalApi_GetEmployeeById_ReturnsEmployee()
    {
        // Arrange
        var id = 1;
        var restClient = new RestClient(new RestClientOptions("https://localhost:7029/"));
        var request = new RestRequest($"/getemployees/{id}");

        // Act
        var response = await restClient.GetAsync(request);
        var result = JsonConvert.DeserializeObject<TrimmedEmployee>(response.Content);

        // Assert
        result.Should().NotBeNull();
        result.Should().BeOfType<TrimmedEmployee>();
        result.EmployeeId.Should().Be(id);
    }
}
