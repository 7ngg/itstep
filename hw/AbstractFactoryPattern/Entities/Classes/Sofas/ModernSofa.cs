using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Sofas
{
    public class ModernSofa : ISofa
    {
        public FurnitureType Type { get; set; }
        public int SeatsCount { get; set; }
    
        public ModernSofa()
        {
            Type = FurnitureType.Modern;
            SeatsCount = 2;
        }
    }
}