using FacadePattern;
using FacadePattern.Subsystems;

DeliverySystem delivery = new();
PaymentSystem payment = new();
ProductSearchSystem search = new();
Facade ProductOrderFacade = new(delivery, payment, search);

Client.Action(ProductOrderFacade);
Console.ReadLine();

public class Client
{
    public static void Action(Facade facade)
    {
        facade.Order();
    }
}