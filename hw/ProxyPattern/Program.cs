using ProxyPattern.Entities.Classes;
using ProxyPattern.Entities.Interfaces;

Client client = new();
Product real = new();
ProductProxy proxy = new(real);
proxy.Data = "changed via Proxy";

System.Console.WriteLine($"From original:\n {client.Method(real)}");
System.Console.WriteLine($"From proxy:\n {client.Method(proxy)}");
Console.ReadLine();

public class Client
{
    public string Method(IEntity entity)
    {
        return $"Type: {entity.GetType().Name}\t Data: {entity.Data}";
    }
}