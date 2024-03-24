using Microsoft.AspNetCore.Mvc;
using Microsoft.AspNetCore.Mvc.RazorPages;
using Newtonsoft.Json;
using SearchApi.Models;

namespace SearchSystem.Pages
{
    public class IndexModel : PageModel
    {
        private readonly HttpClient _client = new();

        public GoogleResponse Responses { get; set; }

        public IndexModel()
        {
        }

        public async Task OnPost(string query)
        {
            _client.BaseAddress = new("https://localhost:7029/");

            var response = await _client.GetAsync($"googlesearch?query={query}");
            var deserializedResponse = JsonConvert.DeserializeObject<GoogleResponse>(await response.Content.ReadAsStringAsync());

            Responses = deserializedResponse;
        }
    }
}
