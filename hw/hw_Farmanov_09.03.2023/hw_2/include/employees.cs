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


        public abstract void Print();
    }

    public class President : Worker
    {
        public President() : base(
            "Name",
            "Surname",
            ""
        ) {}

        public override void Print()
        {
            System.Console.WriteLine($"{FirstName} {LastName}");
        }
    }

    public class Security : Worker
    {
        public Security(string firstName, string lastName) : base(firstName, lastName)
        {
        }
    }

    public class Manager : Worker
    {
        public Manager(string firstName, string lastName) : base(firstName, lastName)
        {
        }
    }

    public class Engineer : Worker
    {
        public Engineer(string firstName, string lastName) : base(firstName, lastName)
        {
        }
    }
}