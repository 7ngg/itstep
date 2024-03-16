using System.Text;
using AsyncAwait.Model;
using Newtonsoft.Json;

namespace AsyncAwait.Tasks
{
    public static partial class Tasks123
    {
        public static int GetSentencesCount(string text)
        {
            int counter = 0;
            char[] keys = { '.', '?', '!' };

            for (int i = 0; i < text.Length; i++)
            {
                if (keys.Contains(text[i]))
                {
                    counter++;

                    if (i < text.Length - 1 && keys.Contains(text[i + 1]))
                    {
                        i++;
                    }
                }
            }

            return counter;
        }

        public static int GetCharsCount(string text) 
            => text.Where(c => c != ' ').Count();

        public static int GetWordsCount(string text)
            => text.Split(' ').Count();

        public static int GetInterrogativesCount(string text)
            => text.Where(c => c == '?').Count();

        public static int GetExclamatoriesCount(string text)
            => text.Where(c => c == '!').Count();

        public static async Task GetReport(string text)
        {
            var report = await CreateReport(text);

            System.Console.WriteLine("Report is created. Select action:");
            System.Console.WriteLine("1. Print");
            System.Console.WriteLine("2. Save to file");
            
            var choice = Convert.ToInt32(Console.ReadLine());
            
            switch (choice)
            {
                default:
                    System.Console.WriteLine("No such option");
                    break;

                case 1:
                    System.Console.WriteLine(report);
                    break;

                case 2:
                    await SaveReport(report);
                    break;
            }
        }

        private static async Task<Report> CreateReport(string text)
        {
            if (text == null)
                throw new ArgumentNullException(nameof(text));

            var tasks = new Task<int>[]
            {
                Task.Run(() => GetSentencesCount(text)),
                Task.Run(() => GetCharsCount(text)),
                Task.Run(() => GetWordsCount(text)),
                Task.Run(() => GetInterrogativesCount(text)),
                Task.Run(() => GetExclamatoriesCount(text))
            };

            await Task.WhenAll(tasks);

            var builder = new StringBuilder();

            var report = new Report
            {
                Text = text,
                SentencesCount = tasks[0].Result,
                CharachtersCount = tasks[1].Result,
                WordsCount = tasks[2].Result,
                InterrogativeSentencesCount = tasks[3].Result,
                ExclamatorySentencesCount = tasks[4].Result
            };

            return report;
        }

        private static async Task SaveReport(Report report)
        {
            var json = JsonConvert.SerializeObject(report, Formatting.Indented);

            using var fs = new FileStream("report.json", FileMode.OpenOrCreate);
            using var sw = new StreamWriter(fs);

            await sw.WriteAsync(json);
        }
    }

}
