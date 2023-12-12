using FlyweightPattern.Entities;
using FlyweightPattern.Factories;

ParticleFactory factory = new(
    new Particle() { Color = "Blue", Coord = "0 0 0", Sprite = "Aqua", Speed = 5 },
    new Particle() { Color = "White", Coord = "1 1 1", Sprite = "Sky", Speed = 0 },
    new Particle() { Color = "Red", Coord = "-1 -1 -1", Sprite = "Fire", Speed = 12 }
);

Particle newParticle = new() { Color = "Red", Coord = "10 12 8", Sprite = "new sprtie", Speed = 20 };
var p = factory.GetParticle(newParticle);
p.Draw(newParticle);

Console.ReadLine();