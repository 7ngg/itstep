using FastEndpoints;
using Microsoft.EntityFrameworkCore;
using RabbitHw;
using RabbitHw.Database;
using RabbitHw.RabbitMq;
using RabbitMQ.Client;
using Scalar.AspNetCore;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();
builder.Services.AddFastEndpoints();

builder.Services.AddDbContext<AppDbContext>(opts => opts.UseInMemoryDatabase("AppInMemo"));

builder.Services.AddSingleton(new ConnectionFactory { HostName = "localhost" });
builder.Services.AddSingleton<Producer>();
builder.Services.AddSingleton<Consumer>();
builder.Services.AddHostedService<ExerciseCreationService>();

var app = builder.Build();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger(opts => opts.RouteTemplate = "openapi/{documentName}.json");
    app.MapScalarApiReference();
}

app.UseFastEndpoints();

app.UseHttpsRedirection();

app.Run();

