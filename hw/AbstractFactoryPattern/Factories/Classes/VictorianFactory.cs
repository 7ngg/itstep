using AbstractFactoryPattern.Entities.Classes.Chairs;
using AbstractFactoryPattern.Entities.Classes.Sofas;
using AbstractFactoryPattern.Entities.Classes.Tables;
using AbstractFactoryPattern.Entities.Interfaces;
using AbstractFactoryPattern.Factories.Interfaces;

namespace AbstractFactoryPattern.Factories.Classes
{
    public class VictorianFactory : IFurnitureFactory
    {
        public IChair CreateChair() => new VictorianChair();

        public ISofa CreateSofa() => new VictorianSofa();

        public ITable CreateTable() => new VictorianTable();
    }
}