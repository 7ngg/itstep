using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Chairs
{
    public class VictorianChair : IChair
    {
        public FurnitureType Type { get; set; }
        public int LegsCount { get; set; }

        public VictorianChair()
        {
            Type = FurnitureType.Victorian;
            LegsCount = 4;
        }
    }
}