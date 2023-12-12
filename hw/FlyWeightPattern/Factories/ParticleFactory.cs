using FlyweightPattern.Entities;

namespace FlyweightPattern.Factories
{
    public class ParticleFactory
    {
        private List<FlyweightParticle> _particles = [];

        public ParticleFactory(params Particle[] patricleSharedAttributes)
        {
            foreach (var item in patricleSharedAttributes)
            {
                _particles.Add(new(item));
            }
        }

        public FlyweightParticle GetParticle(Particle particle)
        {
            if (!_particles.Where(p => p.Equals(particle)).Any())
            {
                System.Console.WriteLine("Creating new particle...");
                _particles.Add(new(particle));
            }
            else
            {
                System.Console.WriteLine("Particle already exists");
            }

            return _particles.FirstOrDefault(p => p.Equals(particle));
        }
    }
}