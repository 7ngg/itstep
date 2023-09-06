namespace BookList
{
    internal class Book {
        public string Title { get; init; }
        public string Author { get; init; }
        public string? Description { get; set; }

        public Book(string title, string author) {
            this.Title = title;
            this.Author = author;
        }


        public void Print() {
            System.Console.WriteLine($"{Title} by {Author}");
        }
    }

    public class BooksToRead {
        internal List<Book> Schedule;

        public BooksToRead()
        {
            Schedule = new List<Book>();
        }


        public void AddBook() 
        {
            System.Console.Write("Book title: ");
            string title = Console.ReadLine();
            System.Console.Write("Author: ");
            string author = Console.ReadLine();
            Schedule.Add(new Book(title, author));
        }

        public void RemoveBook()
        {
            ShowSchedule();
            Console.Write("Enter book title to remove: ");
            string remove = Console.ReadLine();
            Schedule.RemoveAll(f => f.Title == remove);
        }

        public bool IsScheduled()
        {
            Console.Write("Title: ");
            string title = Console.ReadLine();
            Console.Write("Author: ");
            string author = Console.ReadLine();
            if (Schedule.Contains(new Book(title, author)))
                return true;
            else
                return false;
        }

        public void ShowSchedule()
        {
            foreach (Book book in Schedule)
            {
                System.Console.WriteLine(book.Title);
            }
        }
    }
}