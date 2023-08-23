int taskChoice;

System.Console.Write("Choose task: ");
taskChoice = int.Parse(Console.ReadLine());

switch (taskChoice)
{
    case 1:
    {

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
    }

    case 2:
    {
        int num, percent;
        float result;

        System.Console.Write("Enter num: ");
        num = int.Parse(Console.ReadLine());
        System.Console.Write("Enter percent: ");
        percent = int.Parse(Console.ReadLine());

        result = Convert.ToSingle(num) * percent / 100;
        System.Console.WriteLine($"Result: {result}");

        break;
    }

    case 3:
    {
        int num1, num2, num3, num4;
        int result;

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
    }

    case 4:
    {
        string str;
        int index_1, index_2;

        System.Console.Write("Enter num: ");
        str = Console.ReadLine();

        if (str.Length != 6)
        {
            throw new Exception("Invalid length");
        }

        System.Console.Write("Index to replace 1: ");
        index_1 = int.Parse(Console.ReadLine());
        System.Console.Write("Index to replace 2: ");
        index_2 = int.Parse(Console.ReadLine());

        char tmp = str[index_1];
        char[] tmpStr = str.ToCharArray();
        tmpStr[index_1] = str[index_2];
        tmpStr[index_2] = str[index_1];
        str = new string(tmpStr);
        System.Console.WriteLine($"Result - {str}");

        break;
    }

    case 5:
    {
        

        break;
    }
}