namespace AsyncAwait.Tasks
{
    public static partial class Tasks123
    {
        public static async Task<string> GetSelectiveReport(string text)
        {
            System.Console.Write("""
                    1. Sentences count
                    2. Charachters count
                    3. Words count
                    4. Interrogative sentences count
                    5. Exclamatory sentences count
                    > 
                    """);

            var choice = Convert.ToInt32(Console.ReadLine());

            return choice switch
            {
                1 => $"Sentences count: {await Task.Run(() => GetSentencesCount(text))}",
                2 => $"Charachters count: {await Task.Run(() => GetCharsCount(text))}",
                3 => $"Words count: {await Task.Run(() => GetWordsCount(text))}",
                4 => $"Interrogative sentences count: {await Task.Run(() => GetInterrogativesCount(text))}",
                5 => $"Exclamatory sentences count: {await Task.Run(() => GetExclamatoriesCount(text))}",
                _ => "No such option",
            };
        }
    }
}
