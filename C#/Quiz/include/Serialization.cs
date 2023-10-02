using System.Text.Json;
using include.User;

namespace include.Serialization
{
    public static class UserSerialization
    {
        public static void Export(IEnumerable<UserData> users, string fileName = "userdata.json")
        {
            if (users == null)
            {
                throw new ArgumentNullException(nameof(users));
            }

            using FileStream stream = new(fileName, FileMode.OpenOrCreate);
            using StreamWriter writer = new(stream);
            string json = JsonSerializer.Serialize(users);
            writer.Write(json);
        }


        public static List<UserData> Import(string fileName = "userdata.json")
        {
            using FileStream stream = new(fileName, FileMode.OpenOrCreate);
            using StreamReader reader = new(stream);
            string json = reader.ReadToEnd();
            return JsonSerializer.Deserialize<List<UserData>>(json);
        }
    }
}