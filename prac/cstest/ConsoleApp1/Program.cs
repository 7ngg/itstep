using System;
using System.Linq;

namespace ConsoleApp1
{
    public class Date {
        int dd, mm, yy;

        public Date() {
            dd = Convert.ToInt32(DateTime.Now.Day);
            mm = Convert.ToInt32(DateTime.Now.Month);
            yy = Convert.ToInt32(DateTime.Now.Year);
        }

        public void print() {
            Console.WriteLine($"{dd}.{mm}.{yy}");
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            Date currentDate = new Date();
            currentDate.print();
        }
    }
}
