using Newtonsoft.Json;
using System;

namespace omdbApi.Services.Interfaces
{
    internal interface ISerializationService
    {
        static T Deserialize<T>(string json)
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
