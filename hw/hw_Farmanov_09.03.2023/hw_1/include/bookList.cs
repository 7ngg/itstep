namespace BookList
{
    internal class Book {
        public required string Title;
        public required string Author;
        public string? Description;

        public Book(string title, string author) {
            this.Title = title;
            this.Author = author;
        }


        public void Print() {
            System.Console.WriteLine($"{Title} by {Author}");
        }
    }


    public class BooksToRead {
        
    }
}