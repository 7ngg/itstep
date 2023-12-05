namespace FactoryPattern.Entities.Implementations
{
    public class Truck : IAutomobile
    {
        public AutomobileType Type { get; }
        public int MaxWeight { get; set; }

        public Truck()
        {
            Type = AutomobileType.TRUCK;
        }

        public void ShowInfo() => System.Console.WriteLine($"Max weight: {MaxWeight}\nType: {Type}");
    }
}