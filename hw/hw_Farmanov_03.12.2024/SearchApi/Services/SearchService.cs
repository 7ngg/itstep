using System.Net.Http.Headers;
using Newtonsoft.Json;
using SearchApi.Models;

namespace SearchApi.Services
{
    public static class Search
    {
        private static HttpClient _client = new();

        public static async Task<GoogleResponse> GoogleSearch(string query)
        {
            query = "{" + $"\r\n\"text\":\"{query}\",\r\n\"safesearch\":\"off\",\r\n\"timelimit\":\"\",\r\n\"region\":\"ru-ru\",\r\n\"max_results\":20\r\n" + "}";
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Post,
                RequestUri = new Uri("https://google-api31.p.rapidapi.com/websearch"),
                Headers =
                {
                    { "X-RapidAPI-Key", "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7" },
                    { "X-RapidAPI-Host", "google-api31.p.rapidapi.com" },
                },
                Content = new StringContent(query)
                {
                    Headers =
                    {
                        ContentType = new MediaTypeHeaderValue("application/json")
                    }
                }
            };
            using var response = await _client.SendAsync(request);

            response.EnsureSuccessStatusCode();
            var body = await response.Content.ReadAsStringAsync();
            var deserializedResponse = JsonConvert.DeserializeObject<GoogleResponse>(body) ?? throw new ArgumentNullException(nameof(body));

            return deserializedResponse;
        }

        public static async Task<GoogleImageResponse> GoogleImageSearch(string query)
        {
            query = "{" + $"\r\n\"text\":\"{query}\",\r\n\"safesearch\":\"off\",\r\n\"region\":\"ru-ru\",\r\n\"color\":\"\",\r\n\"size\":\"\",\r\n\"type_image\":\"\",\r\n\"layout\":\"\",\r\n\"max_results\":20\r\n" + "}";
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Post,
                RequestUri = new Uri("https://google-api31.p.rapidapi.com/imagesearch"),
                Headers =
                {
                    { "X-RapidAPI-Key", "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7" },
                    { "X-RapidAPI-Host", "google-api31.p.rapidapi.com" },
                },
                Content = new StringContent(query)
                {
                    Headers =
                    {
                        ContentType = new MediaTypeHeaderValue("application/json")
                    }
                }
            };
            using var response = await _client.SendAsync(request);

            response.EnsureSuccessStatusCode();
            var body = await response.Content.ReadAsStringAsync();
            var deserializedResponse = JsonConvert.DeserializeObject<GoogleImageResponse>(body) ?? throw new ArgumentNullException(nameof(body));

            return deserializedResponse;
        }
    
        public static async Task<BingResponse> BingSearch(string query)
        {
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Get,
                RequestUri = new Uri($"https://bing-search-apis.p.rapidapi.com/api/rapid/web_search?keyword={query}&page=0&size=30"),
                Headers =
                {
                    { "X-RapidAPI-Key", "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7" },
                    { "X-RapidAPI-Host", "bing-search-apis.p.rapidapi.com" },
                },
            };
            using var response = await _client.SendAsync(request);

            response.EnsureSuccessStatusCode();
            var body = await response.Content.ReadAsStringAsync();
            var deserializedResponse = JsonConvert.DeserializeObject<BingResponse>(body) ?? throw new ArgumentNullException(nameof(body));

            return deserializedResponse;
        }
    }
}
