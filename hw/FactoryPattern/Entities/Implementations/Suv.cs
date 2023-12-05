namespace FactoryPattern.Entities.Implementations
{
    public class Suv : IAutomobile
    {
        public AutomobileType Type { get; }
        public int DoorsCount { get; set; }

        public Suv()
        {
            Type = AutomobileType.SUV;
        }

        public void ShowInfo() => System.Console.WriteLine($"Doors count: {DoorsCount}\nType: {Type}");
    }
}