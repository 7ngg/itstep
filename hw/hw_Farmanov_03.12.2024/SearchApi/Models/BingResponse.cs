#nullable disable

using Newtonsoft.Json;

namespace SearchApi.Services
{
    public class Data
    {
        [JsonProperty("items")]
        public List<Item> Items { get; set; }
        [JsonProperty("keyword_related")]
        public List<string> KeywordRelated { get; set; }
        [JsonProperty("question")]
        public List<object> Question { get; set; }
    }

    public class Item
    {
        [JsonProperty("title")]
        public string Title { get; set; }
        [JsonProperty("link")]
        public string Link { get; set; }
        [JsonProperty("description")]
        public string Description { get; set; }
    }

    public class Request
    {
        [JsonProperty("keyword")]
        public string Keyword { get; set; }
        [JsonProperty("page")]
        public int Page { get; set; }
        [JsonProperty("size")]
        public int Size { get; set; }
    }

    public class BingResponse
    {
        [JsonProperty("request")]
        public Request Request { get; set; }
        [JsonProperty("data")]
        public Data Data { get; set; }
        [JsonProperty("in_seconds")]
        public double InSeconds { get; set; }
    }
}
