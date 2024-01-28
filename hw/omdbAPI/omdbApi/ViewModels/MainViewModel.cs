using omdbApi.Models;
using omdbApi.Services.Interfaces;
using Prism.Commands;
using Prism.Mvvm;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace omdbApi.ViewModels
{
    public class MainViewModel : BindableBase
    {
        private readonly IDownloadService _ds;
        private readonly ISerializationService _ss;

        #region Title
        private string _title = string.Empty;
        public string Title { get => _title; set => SetProperty(ref _title, value); }
        #endregion

        #region SearchResult
        private MovieModel _result;
        public MovieModel Result { get => _result; set => SetProperty(ref _result, value); }
        #endregion

        #region SearchCommand
        private DelegateCommand _searchCommand;
        public DelegateCommand SearchCommand
        {
            get => _searchCommand;
            private set => SetProperty(ref _searchCommand, value);
        }
        #endregion

        public MainViewModel(IDownloadService ds, ISerializationService ss)
        {
            _ds = ds;
            _ss = ss;

            SearchCommand = new(OnSearchCommandExecuted);
        }

        private void OnSearchCommandExecuted()
        {
            string url = $@"https://www.omdbapi.com/?apikey=82130204&i={Title}";
            string retrievedData = _ds.Download(url);
            Result = _ss.Deserialize<MovieModel>(retrievedData);
        }
    }
}
