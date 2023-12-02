using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Tables
{
    public class VictorianTable : ITable
    {
        public FurnitureType Type { get; set; }
        public int EdgesCount { get; set; }

        public VictorianTable()
        {
            Type = FurnitureType.Victorian;
            EdgesCount = 4;
        }
    }
}

