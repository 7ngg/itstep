using omdbApi.Services.Interfaces;
using Prism.Commands;
using Prism.Mvvm;
using omdbApiDataLayer.Models;
using omdbApiDataLayer.Contexts;

// tt0468569

namespace omdbApi.ViewModels
{
    public class MainViewModel : BindableBase
    {
        private readonly IDownloadService _ds;
        private readonly ISerializationService _ss;
        private readonly IDataConnectionService _dcs;

        private MoviesContext _context;

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

        #region AddCommand
        private DelegateCommand _addCommand;
        public DelegateCommand AddCommand
        {
            get => _addCommand;
            private set => SetProperty(ref _addCommand, value);
        }
        #endregion

        public MainViewModel(IDownloadService ds, ISerializationService ss, IDataConnectionService dcs)
        {
            _ds = ds;
            _ss = ss;
            _dcs = dcs;

            var opts = _dcs.Configure<MoviesContext>("Home");
            _context = new MoviesContext(opts);

            SearchCommand = new(OnSearchCommandExecuted);
            AddCommand = new(OnAddCommandExecuted);
        }

        private void OnSearchCommandExecuted()
        {
            string url = $@"https://www.omdbapi.com/?apikey=82130204&i={Title}";
            string retrievedData = _ds.Download(url);
            Result = _ss.Deserialize<MovieModel>(retrievedData);
        }

        private void OnAddCommandExecuted()
        {
            _context.Add(Result);
            _context.SaveChanges();
        }
    }
}
