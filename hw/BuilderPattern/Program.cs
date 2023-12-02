using BuilderPattern.Builders.Implementations;
using BuilderPattern.Entities;

DesignerComputerBuilder dBuilder = new();
GamingComputerBuilder gBuilder = new();
OfficeComputerBuilder oBuilder = new();

var designer = ComputerDirector.ConstructComputer(dBuilder);
var gamer = ComputerDirector.ConstructComputer(gBuilder);
var office = ComputerDirector.ConstructComputer(oBuilder);

System.Console.WriteLine(designer);
System.Console.WriteLine(gamer);
System.Console.WriteLine(office);