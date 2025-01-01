using System.Net;
using Microsoft.AspNetCore.Server.Kestrel.Core;
using Server;

var builder = WebApplication.CreateBuilder(args);

builder.WebHost.ConfigureKestrel(opts =>
{
    opts.Listen(IPAddress.Any, 5287, listenOptions =>
    {
        listenOptions.Protocols = HttpProtocols.Http2;
    });
});

builder.Services.AddEndpointsApiExplorer();

builder.Services.AddGrpc();

var app = builder.Build();

app.MapGrpcService<ForecastService>();

app.UseHttpsRedirection();

app.Run();
