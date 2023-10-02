using include.User;

namespace include.Authorization
{
    public static class MyAuthorization
    {
        public static UserData SignUp()
        {
            System.Console.Write("Username: ");
            string? username = Console.ReadLine();
            System.Console.Write("Password: ");
            string? password = Console.ReadLine();
            System.Console.WriteLine("Birth date: ");
            string? birthday = Console.ReadLine();

            if (!string.IsNullOrWhiteSpace(username) || !string.IsNullOrEmpty(password) || !string.IsNullOrWhiteSpace(birthday))
            {
                throw new ArgumentNullException();
            }
            
            return new UserData(username, password, DateOnly.Parse(birthday));
        }
    }
}