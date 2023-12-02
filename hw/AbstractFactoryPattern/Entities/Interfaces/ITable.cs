namespace AbstractFactoryPattern.Entities.Interfaces
{
    public interface ITable
    {
        public FurnitureType Type { get; set; }
        public int EdgesCount { get; set; }
    }
}