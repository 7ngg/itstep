using System.Net;
using include.Serialization;
using include.Authorization;
using include.User;

// Получаем список сущесвтующих пользователей при запуске
var users = new List<UserData>(UserSerialization.Import());
foreach (var item in users)
{
    System.Console.WriteLine(item);
}

// var users = new List<UserData>()
// {
//     new("user1", "password1", new DateOnly()),
//     new("user2", "password2", new DateOnly()),
//     new("user3", "password3", new DateOnly())
// };
// UserSerialization.Export(users);

Console.ReadLine();