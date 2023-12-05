namespace FactoryPattern.Entities.Implementations
{
    public class Sedan : IAutomobile
    {
        public AutomobileType Type { get; }
        public string? SOMESEDANPROPERTYICANTCOMEUPWITH { get; set; }

        public Sedan()
        {
            Type = AutomobileType.SEDAN;
        }

        public void ShowInfo() => System.Console.WriteLine($"SOMESEDANPROPERTYICANTCOMEUPWITH: {SOMESEDANPROPERTYICANTCOMEUPWITH}\nType: {Type}");
    }
}