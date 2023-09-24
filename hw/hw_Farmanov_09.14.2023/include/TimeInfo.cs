using System.Net;
using System.Runtime.CompilerServices;

namespace Include.TimeInfo
{
    public static class TimeInfo
    {
        public static void ShowCurrentDate()
        {
            System.Console.WriteLine(DateOnly.FromDateTime(DateTime.Now));
        }

        public static void ShowCurrentTime()
        {
            System.Console.WriteLine(TimeOnly.FromDateTime(DateTime.Now));
        }

        public static void ShowCurrentDayOfWeek()
        {
            System.Console.WriteLine(DateTime.Now.DayOfWeek);
        }

        public static double CalculateTriangleArea(double a, double b, double c)
        {
            double halfPerimeter = (a + b + c) / 2;
            Func<double, double, double, double, double> GetArea =>
            {
                return Math.Sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
            };
        }
    }
}