using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Sofas
{
    public class VictorianSofa : ISofa
    {
        public FurnitureType Type { get; set; }
        public int SeatsCount { get; set; }
    
        public VictorianSofa()
        {
            Type = FurnitureType.Victorian;
            SeatsCount = 4;
        }
    }
}