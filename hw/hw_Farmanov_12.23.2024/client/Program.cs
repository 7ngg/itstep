using Google.Protobuf.WellKnownTypes;
using Grpc.Core;

var builder = WebApplication.CreateBuilder(args);

builder.Services.AddEndpointsApiExplorer();
builder.Services.AddSwaggerGen();

builder.Services.AddGrpcClient<Forecast.ForecastClient>(opts =>
        opts.Address = new Uri(builder.Configuration["grpc:server-http"]!))
    .ConfigurePrimaryHttpMessageHandler(() => new SocketsHttpHandler
    {
        EnableMultipleHttp2Connections = true,
    });

var app = builder.Build();

app.MapGet("/weatherforecast", async (Forecast.ForecastClient fc) =>
{
    var response = fc.Get(new Empty());

    var forecast = new List<ForecastReply>();

    await foreach (var f in response.ResponseStream.ReadAllAsync())
    {
        Console.WriteLine(f.Summary);
        forecast.Add(f);
    }

    return forecast;
});

if (app.Environment.IsDevelopment())
{
    app.UseSwagger();
    app.UseSwaggerUI();
}

app.UseHttpsRedirection();

app.Run();