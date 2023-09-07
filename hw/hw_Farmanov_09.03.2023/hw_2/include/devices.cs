namespace Devices
{
    public abstract class Device {
        public string Name { get; set;}
        public string Description { get; set;}


        public abstract void Sound();
        public abstract void Show();
        public abstract void Desc();
    }

    public class Kettle : Device {
        public Kettle()
        {
            Name = "Kettle";
            Description = "Kettle description";
        }

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
            System.Console.WriteLine("Kettle sounds");
        }
    }

    class Microwave : Device
    {
        public Microwave()
        {
            Name = "Microwave";
            Description = "Microwave description";
        }


        public override void Sound()
        {
            System.Console.WriteLine("Microwave sounds");
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

    class Car : Device
    {
        public Car()
        {
            Name = "Car";
            Description = "Car description";
        }
    }
}