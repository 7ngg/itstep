using Homework.Data;
using LanguageExt;

namespace Homework.Services.Interfaces;

public interface IForecastService
{
    Task<Option<GetForecastResponse>> GetForecast(string city);
}
