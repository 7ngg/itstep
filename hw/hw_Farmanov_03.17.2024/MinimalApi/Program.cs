using Microsoft.EntityFrameworkCore;
using MinimalApi;
using MinimalApi.Data.Contexts;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddDbContext<NorthwindContext>(opts =>
    {
        opts.UseSqlServer(builder.Configuration.GetConnectionString("Default"));
    });

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.MapGet("getemployees", async (NorthwindContext context) => 
    {
        var employeesList = await context.Employees
            .Select(e => new
                {
                    e.EmployeeId,
                    e.LastName,
                    e.FirstName,
                    e.Address,
                    e.City,
                    e.BirthDate,
                    e.HireDate,
                })
            .ToListAsync();

        return employeesList;
    });

app.MapGet("getemployees/{id}", async (int id, NorthwindContext context) =>
    {
        var employee = await context.Employees.FirstOrDefaultAsync(e => e.EmployeeId == id);

        if (employee is null) return Results.NotFound("No employee with given Id");

        return Results.Ok(employee);
    });

app.MapPost("addproduct", async (Product newProduct, NorthwindContext context) =>
    {
        try
        {
            context.Products.Add(newProduct);
            await context.SaveChangesAsync();
            return Results.Ok($"{newProduct.ProductName} added"); 
        }
        catch (System.Exception e)
        {
            return Results.BadRequest($"{e.Message}\n{e.GetBaseException()}");
        }
    });

app.MapPut("editproductprice/{id}", async (int id, decimal newPrice, NorthwindContext context) =>
    {
        var product = context.Products.Find(id);

        if (product is null) return Results.NotFound($"Product {id} does not exist");

        product.UnitPrice = newPrice;
        await context.SaveChangesAsync();

        return Results.Ok($"Product {id} has been edited successfully");
    });

app.MapDelete("removeemployee/{id}", async (int id, NorthwindContext context) =>
    {
        var employee = await context.Employees.FindAsync(id);
        
        if (employee is null) return Results.NotFound($"Employee {id} does not exist");

        try
        {
            context.Employees.Remove(employee);
            await context.SaveChangesAsync();
            return Results.Ok($"Employee {id} has been removed");
        }
        catch (System.Exception e)
        {
            return Results.BadRequest($"{e.Message}\n{e.GetBaseException()}");
        }
    });

app.Run();
