int taskChoice;

System.Console.Write("Choose task: ");
taskChoice = int.Parse(Console.ReadLine());

switch (taskChoice)
{
    case 1:
    {
        Random random = new Random();
        int[] linear = new int[5];
        int[,] twoDimensional = new int[3, 4];

        for (int i = 0; i < linear.Length; i++)
        {
            linear[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                twoDimensional[i, j] = random.Next(20);
            }
        }

        System.Console.Write("A - ");
        foreach (var item in linear)
        {
            System.Console.Write($"{item} ");
        }

        System.Console.WriteLine();
        Console.WriteLine("B - ");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Console.Write($"{twoDimensional[i, j]} ");
            }
            System.Console.WriteLine();
        }

        int[] minimalElements = new int[2] {linear.Min(), twoDimensional.Cast<int>().Min()};
        int[] maximalElements = new int[2] {linear.Max(), twoDimensional.Cast<int>().Max()};
        System.Console.WriteLine($"Minimal element of both arrays - {minimalElements.Min()}");
        System.Console.WriteLine($"Maximal element of both arrays - {maximalElements.Max()}");
        System.Console.WriteLine($"Sum of two arrays - {linear.Sum() + twoDimensional.Cast<int>().Sum()}");

        int multiplication = 1;
        foreach (var item in linear)
        {
            multiplication *= item;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int i = 0; i < 4; i++)
            {
                multiplication *= twoDimensional[i, j];
            }
        }
        System.Console.WriteLine($"Multiplication - {multiplication}");

        break;
    }
}