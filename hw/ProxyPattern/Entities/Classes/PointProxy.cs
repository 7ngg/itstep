using ProxyPattern.Entities.Interfaces;

namespace ProxyPattern.Entities.Classes
{
    public class PointProxy : IPoint
    {
        private Point _point;

        public PointProxy(Point point)
        {
            _point = point;
        }

        public double GetModule() => _point.GetModule();
    }
}