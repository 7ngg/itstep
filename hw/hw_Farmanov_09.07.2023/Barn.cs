namespace Storage
{
    public class Barn
    {
        
    }

    public class Product {
        private Guid ID { get; }
        protected string Name { get; }
        protected DateOnly ProductionDate { get; }
        protected DateOnly BestBeforeDate { get; }
        protected string NETTO { get; }
        protected string BRUTTO { get; }

        
        // public Product(string name, DateOnly productionDate, DateOnly bestBeforeDate, string NETTO, string BRUTTO)
        // {
        //     ID = new Guid
        //     Name = name;

        // }
    }
}
