using AbstractFactoryPattern.Entities.Classes.Chairs;
using AbstractFactoryPattern.Entities.Classes.Sofas;
using AbstractFactoryPattern.Entities.Classes.Tables;
using AbstractFactoryPattern.Entities.Interfaces;
using AbstractFactoryPattern.Factories.Interfaces;

namespace AbstractFactoryPattern.Factories.Classes
{
    public class ArtDecoFactory : IFurnitureFactory
    {
        public IChair CreateChair() => new ArtDecoChair();
        public ISofa CreateSofa() => new ArtDecoSofa();
        public ITable CreateTable() => new ArtDecoTable();
    }
}