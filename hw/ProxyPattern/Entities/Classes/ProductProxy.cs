using ProxyPattern.Entities.Interfaces;

namespace ProxyPattern.Entities.Classes
{
    public class ProductProxy : IEntity
    {
        private Product _proxy;
        public string Data { get => _proxy.Data; set => _proxy.Data = value; }

        public ProductProxy(Product proxy)
        {
            _proxy = proxy;
        }
    }
}