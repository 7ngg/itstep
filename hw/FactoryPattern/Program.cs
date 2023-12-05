using FactoryPattern.Factories.Implementations;

SedanFactory sedanFactory = new();
SUVFactory suvFactory = new();
TruckFactory truckFactory = new();

var sedan = sedanFactory.CreateAutomobile("prop");
var suv = suvFactory.CreateAutomobile(4);
var truck = truckFactory.CreateAutomobile(300);

sedan.ShowInfo();
suv.ShowInfo();
truck.ShowInfo();

Console.ReadLine();