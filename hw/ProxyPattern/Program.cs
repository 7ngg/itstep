using ProxyPattern.Entities.Classes;
using ProxyPattern.Entities.Interfaces;

Client client = new();
Point real = new() { X = 4, Y = 3 };
PointProxy proxy = new(real);

client.Method(real);
client.Method(proxy);
Console.ReadLine();

public class Client
{
    public void Method(IPoint entity)
    {   
        System.Console.WriteLine(entity.GetModule());
    }
}