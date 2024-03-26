using Bogus;
using MinimalApi;

namespace MinimalApiTests.Services
{
    internal class EntityGenerator
    {
        private readonly Randomizer _randomizer = new();

        public Faker<Employee> EmployeeFaker;
        public Faker<Product> ProductFaker;


        public EntityGenerator()
        {
            EmployeeFaker = new Faker<Employee>()
                .RuleFor(e => e.LastName, f => f.Person.LastName)
                .RuleFor(e => e.FirstName, f => f.Person.FirstName)
                .RuleFor(e => e.Title, f => f.Name.JobTitle())
                .RuleFor(e => e.TitleOfCourtesy, f => f.PickRandom(new[] { "Mr.", "Ms.", "Mrs." }))
                .RuleFor(e => e.BirthDate, f => f.Person.DateOfBirth)
                .RuleFor(e => e.HireDate, f => f.Date.Past())
                .RuleFor(e => e.Address, f => f.Address.StreetAddress())
                .RuleFor(e => e.City, f => f.Address.City())
                .RuleFor(e => e.Region, f => f.Address.State())
                .RuleFor(e => e.PostalCode, f => f.Address.ZipCode())
                .RuleFor(e => e.Country, f => f.Address.Country())
                .RuleFor(e => e.HomePhone, f => f.Phone.PhoneNumber())
                .RuleFor(e => e.Extension, f => f.Random.AlphaNumeric(4))
                .RuleFor(e => e.Notes, f => f.Lorem.Sentence())
                .RuleFor(e => e.ReportsTo, f => f.Random.Int(1, 5))
                .RuleFor(e => e.PhotoPath, f => f.Image.PicsumUrl());

            ProductFaker = new Faker<Product>()
                .RuleFor(p => p.ProductName, f => f.Commerce.ProductName())
                .RuleFor(p => p.SupplierId, f => f.Random.Int(1, 10))
                .RuleFor(p => p.CategoryId, f => f.Random.Int(1, 5))
                .RuleFor(p => p.QuantityPerUnit, f => f.Commerce.Ean13())
                .RuleFor(p => p.UnitPrice, f => f.Random.Decimal(1, 1000))
                .RuleFor(p => p.UnitsInStock, f => f.Random.Short(0, 1000))
                .RuleFor(p => p.UnitsOnOrder, f => f.Random.Short(0, 500))
                .RuleFor(p => p.ReorderLevel, f => f.Random.Short(0, 100))
                .RuleFor(p => p.Discontinued, f => f.Random.Bool())
                .RuleFor(p => p.Category, (f, p) => new Category { CategoryId = (int)p.CategoryId, CategoryName = f.Commerce.Categories(1)[0] })
                .RuleFor(p => p.Supplier, (f, p) => new Supplier { SupplierId = (int)p.SupplierId, CompanyName = f.Company.CompanyName() });
        }
    }
}
