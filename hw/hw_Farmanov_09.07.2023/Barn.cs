using System.Reflection;
using System.Text.Json;

namespace Storage
{
    public class Barn
    {
        public List<Product> ProductList;

        public Barn()
        {
            ProductList = new List<Product>();
        }

        public Barn(string fileName) 
        {
            using FileStream stream = new(fileName, FileMode.Open);
            using StreamReader read = new(stream);
            string json = read.ReadToEnd();
            ProductList = JsonSerializer.Deserialize<List<Product>>(json) ?? new List<Product>();
        }

#region Functions
    
        public void AddProduct(Product newProduct) 
        {
            ProductList.Add(newProduct);
        }

        public void AddProduct()
        {
            System.Console.Write("Name: ");
            string? name = Console.ReadLine();
            System.Console.Write("Production date <yy.mm.dd>: ");
            string? prod = Console.ReadLine();
            System.Console.Write("Best before date: <yy.mm.dd>: ");
            string? exp = Console.ReadLine();
            System.Console.Write("Netto weight: ");
            uint netto = Convert.ToUInt32(Console.ReadLine());
            System.Console.Write("Brutto weight: ");
            uint brutto = Convert.ToUInt32(Console.ReadLine());

            var newProduct = new Product(name, prod, exp, netto, brutto);
            var newProductFields = newProduct.GetType().GetFields(BindingFlags.Instance | BindingFlags.Public | BindingFlags.NonPublic);
            foreach (var item in newProductFields)
            {
                var value = item.GetValue(newProduct) ?? throw new ArgumentNullException($"{item.Name} is null");
            }
            ProductList.Add(newProduct);
        }

        public void RemoveProduct(Product product)
        {
            ProductList.Remove(product);
        }

        public void RemoveProduct(string name)
        {
            ProductList.RemoveAll(f => f.Name == name);
        }

        public void RemoveProduct(Guid id)
        {
            ProductList.RemoveAll(product => product.ID.Equals(id));
        }

        public void RemoveExpired()
        {
            ProductList.RemoveAll(product => product.BestBeforeDate < DateOnly.FromDateTime(DateTime.Now));
        }

        public void Serialize() {
            using FileStream stream = new("product_list.json", FileMode.OpenOrCreate);
            using StreamWriter write = new(stream);

            string json = JsonSerializer.Serialize(ProductList);
            write.WriteLine(json);
        }

        public void Print()
        {
            ProductList.ForEach(product => System.Console.WriteLine(product.ToString()));
        }

        #endregion
    }

    public class Product {
        public Guid ID { get; set; }
        public string Name { get; set; }
        public DateOnly ProductionDate { get; set; }
        public DateOnly BestBeforeDate { get; set; }
        public uint NETTO { get; set; }
        public uint BRUTTO { get; set; }

        public Product() {}

        public Product(string name, string productionDate, string bestBeforeDate, uint nettoWeight, uint bruttoWeight)
        {
            ID = Guid.NewGuid();
            Name = name;
            ProductionDate = DateOnly.Parse(productionDate);
            BestBeforeDate = DateOnly.Parse(bestBeforeDate);
            NETTO = nettoWeight;
            BRUTTO = bruttoWeight;
        }


        public override string ToString()
        {
            return  @$" {ID}: {Name}
                    Produced: {ProductionDate.ToString()} | Best before: {BestBeforeDate.ToString()}
                    Netto: {NETTO} | Brutto: {BRUTTO}";
        }
    }
}
