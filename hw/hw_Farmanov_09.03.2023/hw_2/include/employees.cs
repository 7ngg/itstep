namespace Employees
{
    public abstract class Worker {
        protected string FirstName;
        protected string LastName;
        protected string Bio;
        protected int Age;
        
        public Worker(string firstName, string lastName, string bio, int age)
        {
            FirstName = firstName;
            LastName = lastName;
            Bio = bio;
            Age = age;
        }

        public abstract void PrintInfo();
        public abstract void PrintBio();
    }

    public class President : Worker
    {
        public President() : base(
            "Presi",
            "Dent",
            "President bio",
            49
        ) {}

        public override void PrintInfo()
        {
            System.Console.WriteLine($"{FirstName} {LastName}, {Age}");
        }

        public override void PrintBio()
        {
            System.Console.WriteLine($"President bio: {Bio}");
        }
    }

    public class Security : Worker
    {
        public Security() : base(
            "Secu",
            "Rity",
            "Security bio",
            36
        ) {}

        public override void PrintBio()
        {
            System.Console.WriteLine($"Security bio: {Bio}");
        }

        public override void PrintInfo()
        {
            System.Console.WriteLine($"{FirstName} {LastName}, {Age}");
        }
    }

    public class Manager : Worker
    {
        public Manager() : base(
            "Mana",
            "Ger",
            "Manager bio",
            24
        ) {}

        public override void PrintInfo()
        {
            System.Console.WriteLine($"{FirstName} {LastName}, {Age}");
        }

        public override void PrintBio()
        {
            System.Console.WriteLine($"Manager bio: {Bio}");
        }
    }

    public class Engineer : Worker
    {
        public Engineer() : base(
            "Engi",
            "Neer",
            "Engineer bio",
            34
        ) {}

        public override void PrintInfo()
        {
            System.Console.WriteLine($"{FirstName} {LastName}, {Age}");
        }

        public override void PrintBio()
        {
            System.Console.WriteLine($"Engineer bio: {Bio}");
        }
    }
}