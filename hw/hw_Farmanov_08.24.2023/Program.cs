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
        break;
    }

    default:
        break;
}
