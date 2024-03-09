using System.Net;
using Newtonsoft.Json;
using ResetEvents;

internal class Program
{
    private static void Main(string[] args)
    {
        Console.WriteLine("Hello, World!");
        
        using var are = new AutoResetEvent(false);
        var semaphore = new Semaphore(2, 5);

        for (int i = 0; i < 5; i++) 
        {
            ThreadPool.QueueUserWorkItem((arg) =>
            {
                semaphore.WaitOne();
                are.Set();
                try
                {
                    var randomFact = GetFact().fact;
                    System.Console.WriteLine($"{randomFact}\tFact from thread {Thread.CurrentThread.ManagedThreadId}\t Thread name: {Thread.CurrentThread.Name}");
                }
                catch (System.Exception e)
                {
                    System.Console.WriteLine(e.Message);
                }
                finally
                {
                    semaphore.Release();
                }
            });
        }

        are.WaitOne();
        Thread.Sleep(2000);

        System.Console.WriteLine("Goodbye, World...");
    }

#pragma warning disable SYSLIB0014
    private static Fact GetFact()
    {
        var client = new WebClient();
        var response = client.DownloadString("https://catfact.ninja/fact");
        var fact = JsonConvert.DeserializeObject<Fact>(response) ?? throw new ArgumentNullException(nameof(response));

        return fact;
    }
#pragma warning restore SYSLIB0014
}
