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
                q.Enqueue(1);
                q.Enqueue(2);
                q.Enqueue(3);

                while(q.Size > 0)
                {
                    System.Console.WriteLine($"{q.Dequeue() }");
                }

                break;
            }

            case 3:
            {
                var cq = new CircularQueue<int>(5);
                cq.Enqueue(1);
                cq.Enqueue(2);
                cq.Enqueue(3);
                cq.Enqueue(4);
                cq.Enqueue(5);
                cq.Enqueue(6);
                System.Console.WriteLine(cq.Peek());
                System.Console.WriteLine(cq.Dequeue());
                System.Console.WriteLine(cq.Size);
                System.Console.WriteLine(cq.Peek());;

                break;
            }

            case 4:
            {
                SigleLinkedList<int> list = new(1, 2, 3, 4, 5);
                list.PushFront(0);
                list[3] = new Node<int>(7);
                list.Pop(3);
                list.Print();
                System.Console.WriteLine(list.Contains(6));
                break;
            }

            case 5:
            {
                // DoubleLinkedList<int> list = new(1, 2, 3, 4, 5);
                break;
            }
        }
    }
}