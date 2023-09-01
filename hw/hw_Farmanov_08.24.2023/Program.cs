using ExtensionMethods;
using Task4;
using Task5;
using Task6;

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
        newList.print();
        Console.Write("Ban list: ");
        banList.print();        
        newList.RemoveBanElements(banList);
        System.Console.Write("Result: ");
        newList.print();

        break;
    }

    case 4:
    {
        Console.Write("Website name: ");
        string websiteName = Console.ReadLine() ?? throw new NullReferenceException();
        Website site = new() { Name = websiteName, IP = "0.0.0.0"};
        site.edit();
        site.print();

        break;
    }

    case 5:
    {
        Console.Write("Magazine name: ");
        string magazineName = Console.ReadLine() ?? throw new NullReferenceException();
        Magazine newMagazine = new() { Name = magazineName };
        newMagazine.edit();
        newMagazine.print();

        break;
    }

    case 6:
    {
        Console.Write("Store name: ");
        string storeName = Console.ReadLine() ?? throw new NullReferenceException();
        Console.Write("Address: ");
        string storeAddress = Console.ReadLine() ?? "None";
        Store newStore = new() { Name = storeName, Address = storeAddress};

        break;
    }

    default:
        break;
}
