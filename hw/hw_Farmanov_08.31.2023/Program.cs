using Integers;

Console.Write("Select task: ");
int taskChoice = Convert.ToInt32(Console.ReadLine());


switch (taskChoice)
{
    case 1:
    {

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
        
        break;
    }

    default:
        break;
}