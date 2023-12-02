using AbstractFactoryPattern.Entities.Interfaces;

namespace AbstractFactoryPattern.Entities.Classes
{
    public class Room
    {
        public IChair Chair { get; set; }
        public ISofa Sofa { get; set; }
        public ITable Table { get; set; }

        public override string ToString()
        {
            return $"Chair: {Chair.Type}\nSofa: {Sofa.Type}\nTable: {Table.Type}";
        }
    }
}