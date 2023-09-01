using System.Data;

namespace Task5
{
    class Magazine {
        public required string Name { get; set; }
        public DateOnly FoundationDate { get; init; }
        public string? ContactPhone { get; set; }
        public string? ContactEmail { get; set; }

        public Magazine() {
            Console.WriteLine("Foundation date: ");
            Console.Write("Year: ");
            int yy = Convert.ToInt32(Console.ReadLine());
            Console.Write("Month: ");
            int mm = Convert.ToInt32(Console.ReadLine());
            Console.Write("Day: ");
            int dd = Convert.ToInt32(Console.ReadLine());
            FoundationDate = new DateOnly(yy, mm, dd);
        }


        public void print() {
            System.Console.WriteLine(
                $"Name: {Name ?? throw new NullReferenceException()}\n" +
                $"Foundation date: {FoundationDate.ToString()}\n" +
                $"Phone: {ContactPhone??= "None"}\n" +
                $"Email: {ContactEmail??= "None"}\n"
            );
        }


        public void edit() {
            System.Console.WriteLine(
                "1. Name\n" +
                "2. Contact phone" +
                "3. Contact email" +
                "> "
            );
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                {
                    Console.Write("New name: ");
                    Name = Console.ReadLine() ?? throw new Exception("Name cannot be null");
                    break;
                }

                case 2:
                {
                    Console.Write("Contact phone: ");
                    ContactPhone = Console.ReadLine();
                    break;
                }

                case 3:
                {
                    Console.Write("Contact email: ");
                    ContactEmail = Console.ReadLine();
                    break;
                }

                default:
                    break;
            }
        }
    }
}