using FactoryPattern.Entities;

namespace FactoryPattern.Factories
{
    public interface IAutomobileFactory
    {
        public IAutomobile CreateAutomobile(object? p = null);
    }
}