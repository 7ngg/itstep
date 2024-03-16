using BusStopHW.Models;

namespace BusStopHW.Factories
{
    public static class BusFactory
    {
        public static Bus Create() => new Bus();
        public static IEnumerable<Bus> Create(int count)
        {
            List<Bus> depot = [];

            for (int i = 0; i < count; i++)
            {
                depot.Add(new());
            }

            return depot;
        }
    }
}
