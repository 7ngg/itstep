using Microsoft.EntityFrameworkCore;
using Server.Data;
using Server.Data.Models;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddCors(opts => opts.AddDefaultPolicy(policyBuilder =>
{
    policyBuilder
        .AllowAnyOrigin()
        .AllowAnyHeader()
        .AllowAnyMethod();
}));

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddDbContext<AppDbContext>(opts =>
{
    opts.UseNpgsql(builder.Configuration.GetConnectionString("local"));
});

var app = builder.Build();

app.UseCors();

Migrate();

app.MapGet("/users", async (AppDbContext context) => await context.Users.ToArrayAsync());
app.MapGet("/users/{id:guid}", async (AppDbContext context, Guid id) =>
    await context.Users.FirstOrDefaultAsync(u => u.Id == id));

app.MapPost("/users", async (AppDbContext context, UserCreateRequest req) =>
{
    var user = new User
    {
        Email = req.Email,
        Firstname = req.Firstname,
        Lastname = req.Lastname,
        Age = req.Age
    };

    await context.Users.AddAsync(user);
    await context.SaveChangesAsync();

    return user;
});

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.Run();

void Migrate()
{
    using var scope = app.Services.CreateScope();

    var ctx = scope.ServiceProvider.GetRequiredService<AppDbContext>();

    if (!ctx.Database.EnsureCreated())
    {
        ctx.Database.Migrate();
    }
}

record UserCreateRequest(string Email, string Firstname, string Lastname, int Age);

