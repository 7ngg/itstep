using Prism.Mvvm;
using System.Net.Sockets;
using System.Net;
using System.Text;
using System.Windows;
using Prism.Commands;
using System.Collections.ObjectModel;

namespace Client.ViewModels
{
    internal class MainViewModel : BindableBase
    {
        #region IP Address
        private string? _ipAddress;
        public string? IpAddress { get => _ipAddress; set => SetProperty(ref _ipAddress, value); }
        #endregion

        #region Port
        private string _port = "11000";
        public string Port { get => _port; set => SetProperty(ref _port, value); }
        #endregion

        #region Message
        private string _message;
        public string Message { get => _message; set => SetProperty(ref _message, value); }
        #endregion

        #region Messages
        private ObservableCollection<string> _messages = [];
        public IEnumerable<string> Messages => _messages;
        #endregion

        private Socket _socket;

        public DelegateCommand ConnectCommand { get; }
        public DelegateCommand SendCommand { get; }

        public MainViewModel()
        {
            ConnectCommand = new(async () => await OnConnectCommandExecuted());
            SendCommand = new(async () => await OnSendCommandExecuted());
        }

        private async Task OnConnectCommandExecuted()
        {
            var ip = IPAddress.Parse(IpAddress);
            var port = Convert.ToInt32(Port);
            var ipEndPoint = new IPEndPoint(ip, port);
            _socket = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

            try
            {
                await _socket.ConnectAsync(ipEndPoint);
                MessageBox.Show("Connection successful");

                while (true)
                {
                    var bytes = new byte[1024];
                    var receivedBytes = await _socket.ReceiveAsync(bytes);
                    var data = Encoding.UTF8.GetString(bytes, 0, receivedBytes);

                    App.Current.Dispatcher.Invoke(() =>
                    {
                        _messages.Add(data);
                    });
                }
            }
            catch (Exception e)
            {
                MessageBox.Show(e.Message);
            }
            finally
            {
                _socket.Shutdown(SocketShutdown.Both);
                _socket.Close();
            }
        }

        private async Task OnSendCommandExecuted()
        {
            var bytes = Encoding.UTF8.GetBytes(Message);
            await _socket.SendAsync(bytes);
            _messages.Add(Message);
        }
    }
}
