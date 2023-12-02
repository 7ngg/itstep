using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Tables
{
    public class ModernTable : ITable
    {
        public FurnitureType Type { get; set; }
        public int EdgesCount { get; set; }

        public ModernTable()
        {
            Type = FurnitureType.Modern;
            EdgesCount = 0;
        }
    }
}

