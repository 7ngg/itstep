using Newtonsoft.Json;
using Pair = (int, int);

AutoResetEvent _generateEvent = new(true);
AutoResetEvent _sumEvent = new(false);

List<Pair> _pairs = [];
List<int> _sums = [];
List<int> _prods = [];

ThreadPool.QueueUserWorkItem((arg) => Generate());
ThreadPool.QueueUserWorkItem((arg) => CalculatePairSum());
ThreadPool.QueueUserWorkItem((arg) => CalculatePairsProduct());

_generateEvent.WaitOne();

await Save();
System.Console.WriteLine("Done. See results in data.json");


void Generate()
{
    Random random = new();

    for (int i = 0; i < 3; i++)
    {
        _pairs.Add((random.Next(10), random.Next(10)));
    }

    _generateEvent.Set();
}

void CalculatePairSum()
{
    _generateEvent.WaitOne();

    foreach (var pair in _pairs)
    {
        _sums.Add(pair.Item1 + pair.Item2);
    }

    _sumEvent.Set();
}

void CalculatePairsProduct()
{
    _sumEvent.WaitOne();

    foreach (var pair in _pairs)
    {
        _prods.Add(pair.Item1 * pair.Item2);
    }
}

async Task Save()
{
    var obj = new
    {
        InitialPairs = _pairs,
        Sums = _sums,
        Prods = _prods
    };

    var serializedObj = JsonConvert.SerializeObject(obj, Formatting.Indented);
    using var fileStream = new FileStream("data.json", FileMode.OpenOrCreate);
    using var streamWriter = new StreamWriter(fileStream);

    await streamWriter.WriteLineAsync(serializedObj);
}

