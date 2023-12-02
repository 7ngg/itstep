using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Factories.Interfaces
{
    public interface IFurnitureFactory
    {
        public IChair CreateChair();
        public ITable CreateTable();
        public ISofa CreateSofa();
    }
}