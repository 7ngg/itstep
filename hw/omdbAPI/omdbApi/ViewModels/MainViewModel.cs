using omdbApi.Services.Interfaces;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace omdbApi.ViewModels
{
    public class MainViewModel
    {
        public event PropertyChangedEventHandler? PropertyChanged;
        public string Title { get; set; } = "Label";
        public string Query { get; set; }


        public MainViewModel()
        {
            
        }

        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        protected virtual bool Set<T>(ref T field, T value, [CallerMemberName] string propertyName = null)
        {
            if (Equals(field, value)) return false;
            field = value;
            OnPropertyChanged(propertyName);
            return true;
        }
    }
}
