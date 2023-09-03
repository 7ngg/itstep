namespace Passport
{
    internal class LFP {
        public required string firstName { get; set; }
        public required string lastName  { get; set; }
        public string? patronymic { get; set; }
    }


    public class PassportConfiguration {
        public string PassportNO { get; }
        LFP name;
        DateOnly issuedOn;
        DateOnly expiresOn;

        public PassportConfiguration(string _firstName, string _lastName)
        {
            Random random= new Random();
            PassportNO = random.Next(99999999).ToString();
            name = new LFP { firstName = _firstName, lastName = _lastName };
            issuedOn = DateOnly.FromDateTime(DateTime.Now);
            expiresOn = DateOnly.FromDateTime(DateTime.Now);
            expiresOn.AddYears(4);
        }


        public void Print() {
            System.Console.WriteLine(
                $"NO: {passportNO}" +
                $"Name: {name.firstName}    LastName: {name.lastName}   Patronymic: {name.patronymic ?? "None"}" +
                $""
            );
        }
    }
}