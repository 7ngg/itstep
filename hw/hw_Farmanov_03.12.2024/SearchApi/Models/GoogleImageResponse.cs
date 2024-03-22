#nullable disable

using Newtonsoft.Json;

namespace SearchApi.Models
{
    public class ImageResult
    {
        [JsonProperty("title")]
        public string Title { get; set; }
        [JsonProperty("image")]
        public string Image { get; set; }
        [JsonProperty("thumbnail")]
        public string Thumbnail { get; set; }
        [JsonProperty("url")]
        public string Url { get; set; }
        [JsonProperty("height")]
        public int Height { get; set; }
        [JsonProperty("width")]
        public int Width { get; set; }
        [JsonProperty("source")]
        public string Source { get; set; }
    }

    public class GoogleImageResponse
    {
        [JsonProperty("result")]
        public List<ImageResult> Result { get; set; }
    }


}
