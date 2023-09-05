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


        internal void AddBook(string title, string author) 
        {
            Schedule.Add(new Book(title, author));
        }

        internal void RemoveBook(Book book)
        {
            Schedule.Remove(book);
        }

        internal bool IsScheduled(Book book)
        {
            return Schedule.Contains(book);
        }

        internal void showSchedule()
        {
            foreach (Book book in Schedule)
            {
                System.Console.WriteLine(book.Title);
            }
        }
    }
}