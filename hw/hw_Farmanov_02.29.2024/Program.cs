using AsyncAwait.Services;
using AsyncAwait.Tasks;

Console.WriteLine("Hello, World!");

var text = await RandomTextGenerator.Get(2);
System.Console.WriteLine(text);

await Tasks123.GetReport(text);
