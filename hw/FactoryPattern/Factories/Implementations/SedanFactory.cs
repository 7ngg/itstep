using FactoryPattern.Entities;
using FactoryPattern.Entities.Implementations;

namespace FactoryPattern.Factories.Implementations
{
    public class SedanFactory : IAutomobileFactory
    {
        public IAutomobile CreateAutomobile(object? p) => new Sedan() { SOMESEDANPROPERTYICANTCOMEUPWITH = Convert.ToString(p) };
    }
}