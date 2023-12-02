namespace AbstractFactoryPattern.Entities.Interfaces
{
    public interface ISofa
    {
        public FurnitureType Type { get; set; }
        public int SeatsCount { get; set; }
    }
}