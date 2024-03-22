#nullable disable

using Newtonsoft.Json;

namespace SearchApi.Models
{
    public class Result
    {
        [JsonProperty("title")]
        public string Title { get; set; }
        [JsonProperty("href")]
        public string Href { get; set; }
        [JsonProperty("body")]
        public string Body { get; set; }
    }

    public class GoogleResponse
    {
        [JsonProperty("result")]
        public List<Result> Result { get; set; }
    }

}
