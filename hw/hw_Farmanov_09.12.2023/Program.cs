using DynamicStructures;

internal class Program
{
    public static void Swap<T>(ref T var1, ref T var2)
    {
        (var1, var2) = (var2, var1);
    }

    private static void Main(string[] args)
    {
        System.Console.Write("Select task: ");
        int taskChoice = Convert.ToInt32(Console.ReadLine());

        switch (taskChoice)
        {
            case 1:
            {
                int x = 1;
                int y = 2;
                System.Console.WriteLine($"x: {x}   |   y: {y}");
                Swap<int>(ref x, ref y);
                System.Console.WriteLine($"x: {x}   |   y: {y}");
                break;
            }

            case 2:
            {
                var q = new PriorityQueue<int>();
                q.Enqueue(5);
                q.Enqueue(2);
                q.Enqueue(8);

                while(q.Size > 0)
                {
                    System.Console.WriteLine($"{q.Dequeue() }");
                }

                break;
            }

            case 3:
            {
                SigleLinkedList<int> list = new(1, 2, 3, 4, 5);
                list.Print();

                break;
            }
        }
    }
}