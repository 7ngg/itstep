using System.Net.Http;

namespace omdbApi.Services.Interfaces
{
    internal interface IDownloadService
    {
        static string Download(string url)
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
