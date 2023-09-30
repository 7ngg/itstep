using Include.IntArrayExtensions;
using Include.TimeInfo;
using Transactions;

Console.Write("Select task: ");
int choice = Convert.ToInt32(Console.ReadLine());

switch (choice)
{
    case 1:
    {
        int[] arr = new int[] {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 17, 14, 21}; 
        var result = arr.GetAllFibonacci();
        foreach (var item in result)
        {
            Console.Write($"{item} ");
        }
        break;
    }
    
    case 2:
    {
        TimeInfo.ShowCurrentDate();
        TimeInfo.ShowCurrentTime();
        TimeInfo.ShowCurrentDayOfWeek();
        System.Console.WriteLine(TimeInfo.CalculateTriangleArea(3, 4, 5));
        System.Console.WriteLine(TimeInfo.CalculateRectangleArea(4, 5));
        break;
    }

    case 3:
    {
        var cc = new CreditCard("Mahammad", "Farmanov", "Albertovich");
        System.Console.WriteLine(cc.ClientName);
        System.Console.WriteLine(cc.Balance);
        cc.TopUp(2999);
        System.Console.WriteLine(cc.Balance);
        cc.TopUp(1);
        System.Console.WriteLine(cc.Balance);
        cc.Withdraw(3002);
        System.Console.WriteLine(cc.Balance);
        break;
    }
}

Console.ReadLine();
