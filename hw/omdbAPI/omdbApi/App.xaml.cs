using omdbApi.ViewModels;
using omdbApi.Views;
using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace omdbApi
{
    public partial class App : Application
    {
        protected override void OnStartup(StartupEventArgs e)
        {
            var model = new MainViewModel();
            var window = new MainView { DataContext = model };
            window.ShowDialog();
        }
    }
}
