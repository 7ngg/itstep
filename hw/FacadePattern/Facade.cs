using FacadePattern.Subsystems;

namespace FacadePattern
{
    public class Facade
    {
        protected DeliverySystem delivery;
        protected PaymentSystem payment;
        protected ProductSearchSystem search;

        public Facade(DeliverySystem delivery, PaymentSystem payment, ProductSearchSystem search)
        {
            this.delivery = delivery;
            this.payment = payment;
            this.search = search;
        }

        public void Order()
        {
            search.Search();
            payment.Pay();
            delivery.Deliver();
        }
    }
}