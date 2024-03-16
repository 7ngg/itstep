namespace AsyncAwait.Model
{
    public class Report
    {
        public required string Text { get; set; }
        public int SentencesCount { get; set; }
        public int CharachtersCount { get; set; }
        public int WordsCount { get; set; }
        public int InterrogativeSentencesCount { get; set; }
        public int ExclamatorySentencesCount { get; set; }

        public override string ToString()
        {
            var str = $"""
                    Sentences count: {SentencesCount}
                    Charachters count: {CharachtersCount}
                    Words count: {WordsCount}
                    Interrogative sentences count: {InterrogativeSentencesCount}
                    Exclamatory sentences count: {ExclamatorySentencesCount}
                """;

            return str;
        }
    }
}
