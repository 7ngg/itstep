using FastEndpoints;
using Homework.Services;
using Homework.Services.Interfaces;
using Scalar.AspNetCore;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddFastEndpoints();

builder.Services.AddScoped<IForecastService, ForecastService>();
builder.Services.AddHttpClient<IForecastService, ForecastService>(client =>
    client.BaseAddress = new Uri(builder.Configuration["OpenWeatherMap:BaseUrl"]!));

var app = builder.Build();

app.UseHttpsRedirection();

app.UseFastEndpoints();

if (app.Environment.IsDevelopment())
{
    app.UseSwagger(options =>
    {
        options.RouteTemplate = "/openapi/{documentName}.json";
    });
    app.UseSwaggerUI();
    app.MapScalarApiReference();
}

app.Run();

