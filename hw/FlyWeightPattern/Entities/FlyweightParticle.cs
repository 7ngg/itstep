namespace FlyweightPattern.Entities
{
    public class FlyweightParticle(Particle shared)
    {
        private Particle _shared = shared;

        public void Draw(Particle p)
        {
            System.Console.WriteLine($"Particle drawn at: {p.Coord}\nParticle moving speed: {p.Speed}\n{_shared.GetSharedAttributes()}");
        }

        public override bool Equals(object? obj)
        {
            if (obj is not Particle other) return false;

            if (_shared.Equals(other)) return true;

            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}