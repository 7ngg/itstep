using Newtonsoft.Json;
using System;

namespace omdbApi.Services.Interfaces
{
    public interface ISerializationService
    {
        T Deserialize<T>(string json);
    }
}
