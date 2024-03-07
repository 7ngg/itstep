internal class Program
{
    private static ManualResetEvent _mre = new(false);

    private static void Main(string[] args)
    {
        Console.WriteLine("Hello, World!");

        for (int i = 0; i < 3; i++)
        {
            var thread = new Thread(SomeAction);
            thread.Start();
        }

        _mre.WaitOne();
    }

    private static void SomeAction()
    {
        _mre.WaitOne();

        for (int i = 0; i < 5; i++)
        {
            System.Console.WriteLine($"Action {i}\tThread: {Thread.CurrentThread.ManagedThreadId}"); 
            Thread.Sleep(100);
        }

        _mre.Set();
    }
}
