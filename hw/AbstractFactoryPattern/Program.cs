using AbstractFactoryPattern.Entities.Classes;
using AbstractFactoryPattern.Factories.Classes;
using AbstractFactoryPattern.Factories.Interfaces;

Client client = new();
System.Console.WriteLine(client.BuyFurniture(new ModernFactory()));


public class Client
{
    public Room BuyFurniture(IFurnitureFactory factory)
    {
        return new Room()
        {
            Chair = factory.CreateChair(),
            Sofa = factory.CreateSofa(),
            Table = factory.CreateTable()
        };
    }
}