using Microsoft.AspNetCore.Mvc.RazorPages;
using Newtonsoft.Json;
using SearchApi.Models;

namespace SearchSystem.Pages
{
    public class IndexModel : PageModel
    {
        private readonly HttpClient _client = new();

        public GoogleResponse Responses { get; set; }
        public GoogleImageResponse ImageResponses { get; set; }

        public IndexModel()
        {
            _client.BaseAddress = new("https://localhost:7029/");
        }

        public async Task OnPostSearch(string query)
        {
            var response = await _client.GetAsync($"googlesearch?query={query}");
            var deserializedResponse = JsonConvert.DeserializeObject<GoogleResponse>(await response.Content.ReadAsStringAsync());

            Responses = deserializedResponse;
        }

        public async Task OnPostImageSearch(string query)
        {
            var response = await _client.GetAsync($"googleimagesearch?query={query}");
            var dr = JsonConvert.DeserializeObject<GoogleImageResponse>(await response.Content.ReadAsStringAsync());

            ImageResponses = dr;
        }
    }
}
