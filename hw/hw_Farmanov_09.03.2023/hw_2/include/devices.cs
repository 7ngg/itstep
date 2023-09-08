namespace Devices
{
    public abstract class Device {
        protected string Name;
        protected string Description;

        public Device(string name, string description)
        {
            Name = name ?? throw new NullReferenceException();
            Description = description;
        }


        public abstract void Sound();
        public abstract void Show();
        public abstract void Desc();
    }

    public class Kettle : Device {
        public Kettle() : base("Kettle", "Kettle description") { }

        public override void Desc()
        {
            System.Console.WriteLine($"Description: {Description}");
        }

        public override void Show()
        {
            System.Console.WriteLine($"Name: {Name}");
        }

        public override void Sound()
        {
            System.Console.WriteLine($"{Name} sounds");
        }
    }

    public class Microwave : Device
    {
        public Microwave() : base("Microwave", "Microwave description") { }


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
    }

    public class Car : Device
    {
        public Car() : base("Car", "Car description") { }


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
    }

    public class Steamboat : Device
    {
        public Steamboat() : base("Steamboat", "Steamboat description") { }


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
    }
}