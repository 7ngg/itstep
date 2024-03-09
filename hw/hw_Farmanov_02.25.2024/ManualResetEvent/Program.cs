class Program
{
    public static void Main()
    {
        Console.WriteLine("Start of main");

        using var autoResetEvent = new AutoResetEvent(false);

        var semaphore = new Semaphore(1, 5);
     
        for (int i = 0; i < 5; i++)
        {
            ThreadPool.QueueUserWorkItem(
            (p) =>
            {
                var res = semaphore.WaitOne();

                autoResetEvent.Set();

                Console.WriteLine($"Is ThreadPool Thread {Thread.CurrentThread.IsThreadPoolThread}");
                Console.WriteLine($"Thread Id: {Thread.CurrentThread.ManagedThreadId}");

                semaphore.Release();
            });

        }
        
        Thread.Sleep(100);

        autoResetEvent.WaitOne();

        Console.WriteLine("End of main");
    }
}
