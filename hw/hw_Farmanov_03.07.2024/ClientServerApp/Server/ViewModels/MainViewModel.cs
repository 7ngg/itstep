using Prism.Commands;
using Prism.Mvvm;
using System.Collections.ObjectModel;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows;

namespace Server.ViewModels
{
    partial class MainViewModel : BindableBase
    {
        #region IP Regex
        [GeneratedRegex("^(?:[0-9]{1,3}\\.){3}[0-9]{1,3}$")]
        private static partial Regex MyRegex();
        private readonly Regex _ipRegex = MyRegex();
        #endregion

        private string _ipAddress = "192.168.100.7";
        private string _port = "11000";

        private TcpListener? _listener;
        private TcpClient? _handler;

        #region Messages
        private ObservableCollection<string> _messages = [];
        public IEnumerable<string> Messages => _messages;
        #endregion

        #region Message
        private string _message;
        public string Message { get => _message; set => SetProperty(ref _message, value); }
        #endregion


        public DelegateCommand SendCommand { get; }

        public MainViewModel()
        {
            ThreadPool.QueueUserWorkItem((arg) => StartAsync());

            SendCommand = new(async () => await OnSendCommandExecuted());
        }


        private async void StartAsync()
        {
            MessageBox.Show("Start working");
            var ip = IPAddress.Parse(_ipAddress);
            var port = Convert.ToInt32(_port);
            var ipEndPoint = new IPEndPoint(ip, 11000);

            try
            {
                _listener = new(ipEndPoint);
                _listener.Start();
                _handler = await _listener.AcceptTcpClientAsync();

                while(true)
                {
                    var buffer = new byte[1024];

                    var bytesRead = await _handler.GetStream().ReadAsync(buffer, 0, buffer.Length);
                    var receivedData = Encoding.UTF8.GetString(buffer, 0, bytesRead);

                    App.Current.Dispatcher.Invoke(() =>
                    {
                        _messages.Add(receivedData);
                    });
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            finally
            {
                _listener?.Stop();
            }
        }

        public async Task OnSendCommandExecuted()
        {
            var bytes = Encoding.UTF8.GetBytes(Message);
            await _handler.GetStream().WriteAsync(bytes, 0, bytes.Length);
            _messages.Add(Message);
        }
    }
}
