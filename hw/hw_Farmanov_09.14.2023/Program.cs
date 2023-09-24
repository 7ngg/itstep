using Include.IntArrayExtensions;
using Include.TimeInfo;

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
        break;
    }
}