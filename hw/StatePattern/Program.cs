using StatePattern;
using StatePattern.States.Implementations;

Phone p = new(new Discharged());
p.ButtonPress();
p.SetState(new Locked());
p.ButtonPress();
p.SetState(new On());
p.ButtonPress();

Console.ReadLine();