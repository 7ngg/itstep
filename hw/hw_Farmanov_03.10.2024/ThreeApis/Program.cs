using ThreeApis.Converters;
using ThreeApis.Services;
using Microsoft.Extensions.DependencyInjection;
using Microsoft.Extensions.Hosting;

var host = Host.CreateDefaultBuilder().ConfigureServices(
    services =>
    {
        services.AddSingleton<HttpClient>();
        services.AddSingleton<IpInfoService>();
        services.AddSingleton<ForecastService>();
    })
    .Build();

Console.WriteLine("Hello, World!");

var ipInfoService = host.Services.GetRequiredService<IpInfoService>();
var forecastService = host.Services.GetRequiredService<ForecastService>();

var data = await ipInfoService.GetData();
var forecast = await forecastService.GetForecast(data.city);

System.Console.WriteLine($"The temperature outside is {((int)forecast.main.temp)}F/{ForecastConverter.FahrenheitToCelsius((int)forecast.main.temp)}C");
