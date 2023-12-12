namespace FlyweightPattern.Entities
{
    public class Particle()
    {
        public string Color { get; set; }
        public string Sprite { get; set; }
        public int Speed { get; set; }
        public string Coord { get; set; }

        public string GetSharedAttributes() => $"Color: {Color}\t Sprite: {Sprite}";

        public override bool Equals(object? obj)
        {
            if (obj is not Particle other) return false;

            if (
                other.Color == Color &&
                other.Sprite == Sprite
            ) return true;

            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}