using Microsoft.Extensions.DependencyInjection;
using Server.ViewModels;
using Server.Views;
using System.Windows;

namespace Server
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private static IServiceProvider? _services;
        public static IServiceProvider Services => _services ??= Initializeservices().BuildServiceProvider();

        private static ServiceCollection Initializeservices()
        {
            var services = new ServiceCollection();

            services.AddSingleton<MainViewModel>();

            services.AddTransient(
                s =>
                {
                    var model = s.GetRequiredService<MainViewModel>();
                    var window = new MainView() { DataContext = model };

                    return window;
                });

            return services;
        }

        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

            Services.GetRequiredService<MainView>().ShowDialog();
        }
    }
}
