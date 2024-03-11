namespace ThreeApis.Converters
{
    public class ForecastConverter
    {
        public static double FahrenheitToCelsius(double c) => (c - 32) * 5 / 9;
    }
}
