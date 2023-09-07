using Trading;

var product = new Product { Name = "name", Paper = 10, Metal = 22};
product.LowerPrice(7.5);
System.Console.WriteLine(product.ToString());