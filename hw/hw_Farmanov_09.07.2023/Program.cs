using Storage;

// var barn = new Barn();
// var p = new Product("Product 1", "2000.06.22", "2023.06.22", 200, 200);
// var q = new Product("Product 2", "2023.06.21", "2023.08.9", 1000, 1200);
// var r = new Product("Product 3", "2022.12.12", "2023.12.12", 100, 120);
// barn.AddProduct(p);
// barn.AddProduct(q);
// barn.AddProduct(r);
// barn.Serialize();
var jsonFileName = "product_list.json";
var barn = new Barn(jsonFileName);
barn.Print();