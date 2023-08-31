using ExtensionMethods;

System.Console.Write("Select task: ");
int taskChoice = Convert.ToInt32(Console.ReadLine());

switch (taskChoice)
{
    case 1:
    {
        Console.Write("Enter length: ");
        int length = Convert.ToInt32(Console.ReadLine());
        Console.Write("Enter character: ");
        char filling = Convert.ToChar(Console.ReadLine());

        for (int i = 0; i < length; i++)
        {
            Console.WriteLine(new string(filling, length));
        }

        break;
    }

    case 2:
    {
        System.Console.WriteLine("Number: ");
        int num = Convert.ToInt32(Console.ReadLine());
        System.Console.WriteLine($"Is palindrome: {num.palindromeCheck()}");

        break;
    }

    case 3:
    {
        List<int> newList = new List<int> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 3 };
        List<int> banList = new List<int> { 3, 0, 7 };
        
        Console.Write("List: ");
        foreach (var item in newList)
        { 
            Console.Write($"{item} ");   
        }
        System.Console.WriteLine();
        Console.Write("Ban list: ");
        foreach (var item in banList)
        {
            Console.Write($"{item} ");
        }
        System.Console.WriteLine();
        newList.RemoveBanElements(banList);
        System.Console.Write("Result: ");
        foreach (var item in newList)
        {
            Console.Write($"{item} ");
        }
        System.Console.WriteLine();

        break;
    }

    default:
        break;
}
