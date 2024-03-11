using Newtonsoft.Json;

namespace ThreeApis.Models
{
    public class IpModel
    {
        [JsonProperty("ip")]
        public string IpAdress { get; set; } 
    }
}
