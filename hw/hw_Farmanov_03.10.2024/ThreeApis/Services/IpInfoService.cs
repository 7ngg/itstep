using Newtonsoft.Json;
using ThreeApis.Models;

namespace ThreeApis.Services
{
    public class IpInfoService(HttpClient client)
    {
        private readonly HttpClient _client = client;

        public async Task<IpModel> GetIP()
        {
            var response = await _client.GetStringAsync("https://api.ipify.org/?format=json");
            var externalIp = JsonConvert.DeserializeObject<IpModel>(response) ?? throw new ArgumentNullException(nameof(response));

            return externalIp;
        }

        public async Task<IpInfoResponse> GetData()
        {
            var externalIp = await GetIP();
            var request = new HttpRequestMessage
            {
                Method = HttpMethod.Post,
                RequestUri = new Uri("https://community-neutrino-ip-info.p.rapidapi.com/ip-info"),
                Headers =
               {
                   { "X-RapidAPI-Key", "9e977b0f6dmsh720fb50431be912p105275jsn018081b5c3e7" },
                   { "X-RapidAPI-Host", "community-neutrino-ip-info.p.rapidapi.com" },
               },
               Content = new FormUrlEncodedContent(new Dictionary<string, string>
                       {
                           { "ip", externalIp.IpAdress },
                           { "reverse-lookup", "checked" },
                       }),
            };

            using var response = await _client.SendAsync(request);
            response.EnsureSuccessStatusCode();
            var body = await response.Content.ReadAsStringAsync();

            var ipInfo = JsonConvert.DeserializeObject<IpInfoResponse>(body) ?? throw new ArgumentNullException(nameof(body));
            return ipInfo;
        }
    }
}
