using Newtonsoft.Json;
using omdbApi.Services.Interfaces;
using System;

namespace omdbApi.Services.Classes
{
    internal class SerializationService : ISerializationService
    {
        public T Deserialize<T>(string json)
        {
            try
            {
                return JsonConvert.DeserializeObject<T>(json) ?? throw new ArgumentNullException(nameof(json));
            }
            catch (Exception)
            {
                throw;
            }
        }
    }
}
