using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Chairs
{
    public class ModernChair : IChair
    {
        public FurnitureType Type { get; set; }
        public int LegsCount { get; set; }

        public ModernChair()
        {
            Type = FurnitureType.Modern;
            LegsCount = 1;
        }
    }
}