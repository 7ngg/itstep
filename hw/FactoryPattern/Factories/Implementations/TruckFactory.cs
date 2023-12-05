using FactoryPattern.Entities;
using FactoryPattern.Entities.Implementations;

namespace FactoryPattern.Factories.Implementations
{
    public class TruckFactory : IAutomobileFactory
    {
        public IAutomobile CreateAutomobile(object? maxWeight) => new Truck() { MaxWeight = Convert.ToInt32(maxWeight) };
    }
}