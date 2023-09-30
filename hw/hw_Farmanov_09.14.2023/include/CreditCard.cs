using System.ComponentModel.DataAnnotations;
using System.Text;

namespace Transactions
{
    public class FLP
    {
        public string FirstName { get; set; }
        public string LastName { get; set; }
        public string Patronymic { get; set; }

        public FLP() {}
        public FLP(string firstName, string lastName, string patronymic)
        {
            FirstName = firstName;
            LastName = lastName;
            Patronymic = patronymic;
        }

        public override string ToString()
        {
            return $"{LastName} {FirstName} {Patronymic}";
        }
    }

    public class CreditCard
    {
        public FLP ClientName { get; init; }
        public string Number { get; init; }
        public DateOnly ExpiresOn { get; }
        public int PIN { get; private set; }
        public int CreditLimit { get; private set; }
        private int _balance;
        public int Balance { 
            get
            {
                return _balance;
            } 

            private set
            {
                _balance = value;
                
                if (_balance >= 3000)
                {
                    SumReachedEvent.Invoke();
                }

                if (_balance < 0)
                {
                    UsingLoanEvent.Invoke();
                }
            }
        }

        public CreditCard(string name, string surname, string patronymic, int balance = 0)
        {
            SumReachedEvent += SumReached;
            UsingLoanEvent += UsingLoan;

            ClientName = new FLP(name, surname, patronymic);
            Number = GenerateCardNo();
            ExpiresOn = GenerateDate();
            PIN = GeneratePIN();
            CreditLimit = 0;
            Balance = (balance >= 0) ? balance : throw new ArgumentException("Invalid balance value");
        }


        public delegate void SumReachedDelegate();
        public event SumReachedDelegate SumReachedEvent;
        private static void SumReached()
        {
            System.Console.WriteLine("Upper limit reached");
        }


        public delegate void UsingLoanDelegate();
        public event UsingLoanDelegate UsingLoanEvent;
        private static void UsingLoan()
        {
            System.Console.WriteLine("You are using loan money");
        } 


        public void TopUp(int value)
        {
            if (value <= 0)
            {
                throw new ArgumentException("Invalid value");
            }
            Balance += value;
        }


        public void Withdraw(int value)
        {
            if (value <= 0)
            {
                throw new ArgumentException("Invalid withdraw amount");
            }

            Balance -= value;
        }


        public void ChangePIN(int newPin)
        {
            if (newPin <= 1000 || newPin > 9999)
            {
                throw new ArgumentException("Inalid PIN");
            }

            PIN = newPin;
        }


        private static string GenerateCardNo()
        {
            StringBuilder tmpCardNo = new();
            Random rnd = new();
            for (int i = 0; i < 4; i++)
                tmpCardNo.Append($"{rnd.Next(1000, 9999)} ");
            return tmpCardNo.ToString();
        }


        private static DateOnly GenerateDate(int expiration = 1)
        {
            return DateOnly.FromDateTime(DateTime.Now).AddYears(expiration);
        }


        private static int GeneratePIN()
        {
            Random random = new();
            return random.Next(1000, 9999);
        }
    }
}