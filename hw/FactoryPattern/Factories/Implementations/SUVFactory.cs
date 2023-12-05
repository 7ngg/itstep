using FactoryPattern.Entities;
using FactoryPattern.Entities.Implementations;

namespace FactoryPattern.Factories.Implementations
{
    public class SUVFactory : IAutomobileFactory
    {
        // public IAutomobile CreateAutomobile() => new Suv();
        public IAutomobile CreateAutomobile(object? doorsCount) => new Suv() { DoorsCount = Convert.ToInt32(doorsCount) };
    }
}