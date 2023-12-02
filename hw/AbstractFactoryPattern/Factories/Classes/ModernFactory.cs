using AbstractFactoryPattern.Entities.Classes.Chairs;
using AbstractFactoryPattern.Entities.Classes.Sofas;
using AbstractFactoryPattern.Entities.Classes.Tables;
using AbstractFactoryPattern.Entities.Interfaces;
using AbstractFactoryPattern.Factories.Interfaces;

namespace AbstractFactoryPattern.Factories.Classes
{
    public class ModernFactory : IFurnitureFactory
    {
        public IChair CreateChair() => new ModernChair();

        public ISofa CreateSofa() => new ModernSofa();

        public ITable CreateTable() => new ModernTable();
    }
}