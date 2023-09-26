namespace Include.TimeInfo
{
    public static class TimeInfo
    {
        public static void ShowCurrentDate()
        {
            Console.WriteLine(DateOnly.FromDateTime(DateTime.Now));
        }

        public static void ShowCurrentTime()
        {
            Console.WriteLine(TimeOnly.FromDateTime(DateTime.Now));
        }

        public static void ShowCurrentDayOfWeek()
        {
            Console.WriteLine(DateTime.Now.DayOfWeek);
        }

        public static double CalculateTriangleArea(double a, double b, double c)
        {
            double halfPerimeter = (a + b + c) / 2;
            Func<double, double, double, double> GetArea = (a, b, c) =>
            {
                return Math.Sqrt(halfPerimeter * (halfPerimeter - a) * (halfPerimeter - b) * (halfPerimeter - c));
            };

            return GetArea(a, b, c);
        }

        public static double CalculateRectangleArea(double height, double width)
        {
            Func<double, double, double> GetArea = (a, b) =>
            {
                return a * b;
            };

            return GetArea(height, width);
        }
    }
}