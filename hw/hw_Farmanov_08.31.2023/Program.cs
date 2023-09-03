using System.Data;
using System.Security.Cryptography;
using Integers;
using Passport;

Console.Write("Select task: ");
int taskChoice = Convert.ToInt32(Console.ReadLine());


switch (taskChoice)
{
    case 1:
    {
        Console.Write("Enter number: ");
        bool check = int.TryParse(Console.ReadLine(), out int num);
        if (!check)
        {
            throw new ArgumentException();
        }
        Console.Write("Required number system: ");
        check = int.TryParse(Console.ReadLine(), out int requiredNumberSystem);
        if (!check)
        {
            throw new ArgumentException();
        }
        System.Console.WriteLine($"Result: {number_system_convert(num, requiredNumberSystem)}");
        break;
    }

    case 2:
    {
        int num = Convert.ToInt32(Console.ReadLine());
        Numbers x = (Numbers)num;
        System.Console.WriteLine(x); 
        break;
    }

    case 3:
    {
        System.Console.Write("Firstname: ");
        string firstName = Console.ReadLine();
        Console.Write("Lastname: ");
        string lastName = Console.ReadLine();
        PassportConfiguration passport = new(firstName, lastName);
        passport.Print();
        break;
    }

    case 4:     // https://sportishka.com/uploads/posts/2022-08/1661365210_1-sportishka-com-p-nakachennii-dogi-instagram-1.jpg
    {
        System.Console.Write("Expression: ");
        string expression = Console.ReadLine();
        string[] operatorsArray = new string[] { "<=", ">=", ">" , "<", "!=", "==" };
        string[] numbers = expression.Split(operatorsArray, StringSplitOptions.None);

        break;
    }

    case 5:     // https://kartinkof.club/uploads/posts/2022-03/1648387937_3-kartinkof-club-p-mem-slabaya-sobaka-3.png
    {
        string expression;

        Console.Write("Expression: ");
        expression = Console.ReadLine();

        var result = new DataTable().Compute(expression, null);
        System.Console.WriteLine($"Result: {result}");
        break;
    }

    default:
        break;
}


static int number_system_convert(int x, int requiredNumberSystem) {
    int result = 0;
    int order = 1;

    while(x > 0)
    {
        result += (x % requiredNumberSystem) * order;
        x /= requiredNumberSystem;
        order *= 10;
    }

    return result;
}