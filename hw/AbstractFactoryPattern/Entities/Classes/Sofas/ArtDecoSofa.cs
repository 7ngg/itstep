using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Sofas
{
    public class ArtDecoSofa : ISofa    
    {
        public FurnitureType Type { get; set; }
        public int SeatsCount { get; set; }

        public ArtDecoSofa()
        {
            Type = FurnitureType.ArtDeco;
            SeatsCount = 3;
        }
    }
}