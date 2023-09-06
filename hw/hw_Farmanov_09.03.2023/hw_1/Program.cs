using Magazine;
using Store;
using BookList;

System.Console.WriteLine("Select task: ");
int taskChoice = Convert.ToInt32(Console.ReadLine());

switch (taskChoice)
{
    case 1:
    {
        string name = "Magazine";
        var newMag = new MagazineProperies { Name = name };
        newMag.print();
        break;
    }

    case 2:
    {
        var store_1 = new StoreProperties { Name = "store_1", Address = "address_1", area = 10};
        var store_2 = new StoreProperties { Name = "store_2", Address = "address_2", area = 10};
        System.Console.WriteLine($"Store 1 area + Store 2 area = {store_1 + store_2.area}");
        System.Console.WriteLine($"Store 2 area - Store 1 area = {store_2 - store_1.area}");
        System.Console.WriteLine($"Store 1 area == Store 2 area: {store_1 == store_2}");
        System.Console.WriteLine($"Store 1 area != Store 2 area: {store_1 != store_2}");
        System.Console.WriteLine($"Store 1 area equals Store 2 area: {store_1.Equals(store_2)}");
        break;
    }

    case 3:
    {
        BooksToRead myList = new();

        System.Console.WriteLine(   
            "1. Add book \n",
            "2. Remove book \n",
            "3. Check if book is in list \n",
            "4. Print list \n",
            "> "
        );
        byte choice = Convert.ToByte(Console.ReadLine());

        switch (choice)
        {
            case 1:
                myList.AddBook();
                break;
            case 2:
                myList.RemoveBook();
                break;
            case 3:
                myList.IsScheduled();
                break;
            case 4:
                myList.ShowSchedule();
                break;
            default:
                break;
        }

        break;
    }

}



