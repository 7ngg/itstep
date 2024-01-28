using Microsoft.Extensions.Configuration;
using omdbApi.Services.Classes;
using omdbApi.Services.Interfaces;
using omdbApi.ViewModels;
using omdbApi.Views;
using SimpleInjector;
using System.Windows;

namespace omdbApi
{
    public partial class App : Application
    {
        public static Container container { get; set; } = new();

        protected override void OnStartup(StartupEventArgs e)
        {
            Register();
            container.GetInstance<MainView>().ShowDialog();
        }

        private void Register()
        {
            container.RegisterSingleton<IDownloadService, DonwloadService>();
            container.RegisterSingleton<ISerializationService, SerializationService>();
            container.RegisterSingleton<IDataConnectionService>(() =>
            {
                IConfigurationBuilder builder = new ConfigurationBuilder();
                return new DataConnectionService(builder);
            });

            container.RegisterSingleton<MainViewModel>();

            container.RegisterSingleton<MainView>(() =>
            {
                var model = container.GetInstance<MainViewModel>();
                var window = new MainView { DataContext = model };
                return window;
            });

            container.Verify();
        }
    }
}
