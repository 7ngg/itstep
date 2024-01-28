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

        private string _title = string.Empty;
        public string Title { get => _title; set => SetProperty(ref _title, value); }

        private Root _result;
        public Root Result { get => _result; set => SetProperty(ref _result, value); }

        public DelegateCommand SearchCommand { get; }


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
            Result = _ss.Deserialize<Root>(retrievedData);
        }
    }
}
