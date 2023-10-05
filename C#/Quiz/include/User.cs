namespace include.User
{
    public class UserData
    {
        public string Username { get; set; }
        public string Password { get; private set; }
        public DateOnly Birthday { get; set; }

        public UserData() {}
        public UserData(string username, string password, DateOnly date)
        {
            Username = username;
            Password = password;
            Birthday = date;
        }


        public override string ToString()
        {
            return $"{Username}, {Birthday}";
        }
    }
}