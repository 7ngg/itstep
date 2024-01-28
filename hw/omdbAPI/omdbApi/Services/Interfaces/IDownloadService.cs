using System.Net.Http;

namespace omdbApi.Services.Interfaces
{
    public interface IDownloadService
    {
        string Download(string url);
    }
}
