namespace AbstractFactoryPattern.Entities.Interfaces
{
    public interface IChair
    {
        public FurnitureType Type { get; set; }
        public int LegsCount { get; set; }
    }
}