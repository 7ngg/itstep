using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Chairs
{
    public class ArtDecoChair : IChair
    {
        public FurnitureType Type { get; set; }
        public int LegsCount { get ; set; }

        public ArtDecoChair()
        {
            Type = FurnitureType.ArtDeco;
            LegsCount = 3;
        }
    }
}