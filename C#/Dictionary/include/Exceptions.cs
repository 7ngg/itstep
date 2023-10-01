namespace Exceptions
{
    [System.Serializable]
    public class InvalidDictionaryNameException : System.Exception
    {
        public InvalidDictionaryNameException() { }
        public InvalidDictionaryNameException(string message) : base(message) { }
    }

    [System.Serializable]
    public class NoSuchWordException : System.Exception
    {
        public NoSuchWordException() { }
        public NoSuchWordException(string message) : base(message) { }
    }
}