using Newtonsoft.Json;

namespace AsyncAwait.Services
{
    public class TextResponse
    {
        [JsonProperty("text")]
        public string Text = null!;
    }

    public static class RandomTextGenerator
    {
        private static HttpClient _client = new();

        public static async Task<string> Get(int sentencesCount)
        {
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                       RequestUri = new Uri($"https://lorem-ipsum-api.p.rapidapi.com/sentence?amount={sentencesCount}"),
                       Headers =
                       {
                           { "X-RapidAPI-Key", "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7" },
                           { "X-RapidAPI-Host", "lorem-ipsum-api.p.rapidapi.com" },
                       },
            };
            using var response = await _client.SendAsync(request);

            response.EnsureSuccessStatusCode();
            var body = await response.Content.ReadAsStringAsync();

            return JsonConvert.DeserializeObject<TextResponse>(body).Text;
        }
    }
}
