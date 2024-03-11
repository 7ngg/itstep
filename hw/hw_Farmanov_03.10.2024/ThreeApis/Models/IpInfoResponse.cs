using Newtonsoft.Json;

namespace ThreeApis.Models
{
#pragma warning disable CS8618
    public class IpInfoResponse
    {
        [JsonProperty("region-code")]
        public string regioncode { get; set; }
        public string country { get; set; }

        [JsonProperty("country-code")]
        public string countrycode { get; set; }
        public string city { get; set; }
        public Timezone timezone { get; set; }
        public string ip { get; set; }
        public double latitude { get; set; }
        public bool valid { get; set; }

        [JsonProperty("is-v4-mapped")]
        public bool isv4mapped { get; set; }
        public string hostname { get; set; }

        [JsonProperty("continent-code")]
        public string continentcode { get; set; }

        [JsonProperty("host-domain")]
        public string hostdomain { get; set; }

        [JsonProperty("currency-code")]
        public string currencycode { get; set; }
        public string region { get; set; }

        [JsonProperty("is-bogon")]
        public bool isbogon { get; set; }

        [JsonProperty("country-code3")]
        public string countrycode3 { get; set; }

        [JsonProperty("is-v6")]
        public bool isv6 { get; set; }
        public double longitude { get; set; }
    }

    public class Timezone
    {
        public string date { get; set; }
        public string offset { get; set; }
        public string name { get; set; }
        public string id { get; set; }
        public string time { get; set; }
        public string abbr { get; set; }
    }
#pragma warning restore CS8618
}
