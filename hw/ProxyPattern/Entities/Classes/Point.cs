using ProxyPattern.Entities.Interfaces;

namespace ProxyPattern.Entities.Classes
{
    public class Point : IPoint
    {
        public double X { get; set; }
        public double Y { get; set; }

        public double GetModule() => Math.Sqrt(X * X + Y * Y);
    }
}