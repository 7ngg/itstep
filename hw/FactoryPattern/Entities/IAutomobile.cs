namespace FactoryPattern.Entities
{
    public interface IAutomobile
    {
        public AutomobileType Type { get; }
        public void ShowInfo();
    }
}