using FluentAssertions;
using Microsoft.EntityFrameworkCore;
using MinimalApi.Data.Contexts;
using MinimalApiTests.Services;
using Newtonsoft.Json;
using Xunit;

namespace MinimalApiTests;

using TrimmedEmployee = (
    int EmployeeId,
    string LastName,
    string FirstName,
    string Address,
    string City,
    DateTime BirthDate,
    DateTime HireDate
);

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
}
