int taskChoice;

System.Console.Write("Choose task: ");
taskChoice = int.Parse(Console.ReadLine());

switch (taskChoice)
{
    case 1:
        int num;
        System.Console.Write("Enter num: ");
        num = int.Parse(Console.ReadLine());

        if (num < 1 || num > 100)
        {
            throw new Exception("Num must be between 1 amd 100");
        }

        if (num % 3 == 0) 
        {
            System.Console.WriteLine("Fizz");
        }
        else if (num % 5 == 0)
        {
            System.Console.WriteLine("Buzz");
        }
        else if (num % 3 == 0 && num % 5 == 0)
        {
            Console.WriteLine("Fizz Buzz");
        }

        break;

    case 2:
        int percent;
        float result;

        System.Console.Write("Enter num: ");
        num = int.Parse(Console.ReadLine());
        System.Console.Write("Enter percent: ");
        percent = int.Parse(Console.ReadLine());

        result = Convert.ToSingle(num) * percent / 100;
        System.Console.WriteLine($"Result: {result}");

        break;

    case 3:
        int num1, num2, num3, num4;

        Console.Write("Num1: ");
        num1 = int.Parse(Console.ReadLine());
        Console.Write("Num2: ");
        num2 = int.Parse(Console.ReadLine());
        Console.Write("Num3: ");
        num3 = int.Parse(Console.ReadLine());
        Console.Write("Num4: ");
        num4 = int.Parse(Console.ReadLine());

        result = num1 * 1000 + num2 * 100 + num3 * 10 + num4;
        System.Console.WriteLine($"Result - {result}");

        break;

    case 4:
        bool b;

        b = int.TryParse(Console.ReadLine(), out num);

        break;
}