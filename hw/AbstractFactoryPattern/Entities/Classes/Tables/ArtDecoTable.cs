using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes.Tables
{
    public class ArtDecoTable : ITable
    {
        public FurnitureType Type { get; set; }
        public int EdgesCount { get; set; }

        public ArtDecoTable()
        {
            Type = FurnitureType.ArtDeco;
            EdgesCount = 4;
        }
    }
}

