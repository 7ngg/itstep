using omdbApi.Services.Interfaces;
using System.Net.Http;

namespace omdbApi.Services.Classes
{
    internal class DonwloadService : IDownloadService
    {
        public string Download(string url)
        {
            try
            {
                var client = new HttpClient();
                var data = client.GetStringAsync(url).Result;

                return data;
            }
            catch (System.Exception)
            {
                throw;
            }
        }
    }
}
