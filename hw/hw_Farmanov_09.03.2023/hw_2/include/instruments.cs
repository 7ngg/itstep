namespace Instruments
{
    public abstract class MusicalInstrument {
        protected string Name;
        protected string Description;
        protected string History;

        public MusicalInstrument(string name, string description, string history)
        {
            Name = name ?? throw new ArgumentNullException(nameof(name));
            Description = description ?? "None";
            History = history ?? "None";
        }


        public abstract void Sound();
        public abstract void Show();
        public abstract void Desc();
        public abstract void ShowHistory();
    }

    public class Violin : MusicalInstrument
    {
        public Violin() : base(
            "Violin",
            "Violin description",
            "Violin history"
        ) {}


        public override void Sound()
        {
            System.Console.WriteLine($"{Name} sounds");
        }

        public override void Show()
        {
            System.Console.WriteLine($"Name: {Name}");
        }

        public override void Desc()
        {
            System.Console.WriteLine($"Description: {Description}");
        }

        public override void ShowHistory()
        {
            System.Console.WriteLine($"History: {History}");
        }
    }

    public class Trombone : MusicalInstrument {
        public Trombone() : base(
            "Trombone",
            "Trombone description",
            "Trombone history"
        ) {}


        public override void Sound()
        {
            System.Console.WriteLine($"{Name} sounds");
        }

        public override void Show()
        {
            System.Console.WriteLine($"Name: {Name}");
        }

        public override void Desc()
        {
            System.Console.WriteLine($"Description: {Description}");
        }

        public override void ShowHistory()
        {
            System.Console.WriteLine($"History: {History}");
        }
    }

    public class Ukulele : MusicalInstrument
    {
        public Ukulele() : base(
            "Ukulele",
            "Ukulele desription",
            "Ukulele history"
        ) {}


        public override void Sound()
        {
            System.Console.WriteLine($"{Name} sounds");
        }

        public override void Show()
        {
            System.Console.WriteLine($"Name: {Name}");
        }

        public override void Desc()
        {
            System.Console.WriteLine($"Description: {Description}");
        }
        public override void ShowHistory()
        {
            System.Console.WriteLine($"History: {History}");
        }
    }

    public class Cello : MusicalInstrument
    {
        public Cello() : base(
            "Cello",
            "Cello description",
            "Cello history"
        ) {}


        public override void Sound()
        {
            System.Console.WriteLine($"{Name} sounds");
        }

        public override void Show()
        {
            System.Console.WriteLine($"Name: {Name}");
        }

        public override void Desc()
        {
            System.Console.WriteLine($"Description: {Description}");
        }

        public override void ShowHistory()
        {
            Console.WriteLine($"History: {History}");
        }
    }
}