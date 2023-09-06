namespace Magazine
{
    class MagazineProperies {
        public required string Name { get; set; }
        public int EmployeesCount { get; set; }
        public DateOnly FoundationDate { get; init; }
        public string? ContactPhone { get; set; }
        public string? ContactEmail { get; set; }

        public MagazineProperies() {
            FoundationDate = new DateOnly();
            FoundationDate = DateOnly.FromDateTime(DateTime.Now);
        }

#region Methods

        public void print() {
            System.Console.WriteLine(
                $"Name: {Name ?? throw new NullReferenceException()}\n" +
                $"Foundation date: {FoundationDate.ToString()}\n" +
                $"Phone: {ContactPhone??= "None"}\n" +
                $"Email: {ContactEmail??= "None"}\n" +
                $"Employees count: {EmployeesCount}\n"
            );
        }


        public void edit() {
            System.Console.WriteLine(
                "1. Name\n" +
                "2. Contact phone" +
                "3. Contact email" +
                "> "
            );
            int choice = Convert.ToInt32(Console.ReadLine());

            switch (choice)
            {
                case 1:
                {
                    Console.Write("New name: ");
                    Name = Console.ReadLine() ?? throw new Exception("Name cannot be null");
                    break;
                }

                case 2:
                {
                    Console.Write("Contact phone: ");
                    ContactPhone = Console.ReadLine();
                    break;
                }

                case 3:
                {
                    Console.Write("Contact email: ");
                    ContactEmail = Console.ReadLine();
                    break;
                }

                default:
                    break;
            }
        }

#endregion

#region Operators
    
    public static int operator + (MagazineProperies mag_1, int increment) {
        return mag_1.EmployeesCount += increment;
    }

    public static int operator - (MagazineProperies mag_1, int increment) {
        if (mag_1.EmployeesCount - increment < 0)
        {
            mag_1.EmployeesCount = 0;
            return mag_1.EmployeesCount;
        }
        return mag_1.EmployeesCount -= increment;
    }

    public static bool operator == (MagazineProperies mag_1, MagazineProperies mag_2) {
        return mag_1.EmployeesCount == mag_2.EmployeesCount;
    }

    public static bool operator != (MagazineProperies mag_1, MagazineProperies mag_2) {
        return mag_1.EmployeesCount != mag_2.EmployeesCount;
    }

    public static bool operator > (MagazineProperies mag_1, MagazineProperies mag_2) {
        return mag_1.EmployeesCount > mag_2.EmployeesCount;
    }

    public static bool operator < (MagazineProperies mag_1, MagazineProperies mag_2) {
        return mag_1.EmployeesCount < mag_2.EmployeesCount;
    }

    public override bool Equals(object? obj)
    {
        if (obj == null || this.GetType() != obj.GetType())
        {
            return false;
        }
        
        MagazineProperies other = (MagazineProperies)obj;
        if (this.EmployeesCount != other.EmployeesCount)
            return false;
        if (this.Name != other.Name)
            return false;
        if(this.FoundationDate != other.FoundationDate)
            return false;
        if(this.ContactPhone != other.ContactPhone)
            return false;
        if (this.ContactEmail != other.ContactEmail)
            return false;

        return true;
    }
    
    public override int GetHashCode()
    {
        return base.GetHashCode();
    }

#endregion

    }
}