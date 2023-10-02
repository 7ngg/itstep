using System.Net;
using include.Serialization;
using include.Authorization;
using include.User;

// Получаем список сущесвтующих пользователей при запуске
var users = new List<UserData>
{
    MyAuthorization.SignUp()
};

// var user_1 = new UserData("user1", "password1", new DateOnly());
// var user_2 = new UserData("user2", "password2", new DateOnly());
// var user_3 = new UserData("user3", "password3", new DateOnly());

// var users = new List<UserData>
// {
//     user_1,
//     user_2,
//     user_3
// };

UserSerialization.Export(users);