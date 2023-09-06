using System.Security.Cryptography;

namespace Store
{
    class StoreProperties {
        public int area;
        public required string Name { get; set; }
        public required string Address { get; set; }
        public string? Description { get; set; }
        public string? ContactPhone { get; set; }
        public string? ContactEmail { get; set; }

        public void print() {
            Console.WriteLine(
                $"Name: {Name}" +
                $"Address: {Address}" +
                $"Description: {Description ?? "None"}" +
                $"Contact phone: {ContactPhone ?? "None"}" +
                $"Contact email: {ContactEmail ?? "None"}"
            );
        }


        public static int operator + (StoreProperties store, int increment)
        {
            return store.area += increment;
        }

        public static int operator - (StoreProperties store, int decrement)
        {
            if (store.area - decrement < 0)
            {
                store.area = 0;
                return store.area;
            }
            return store.area -= decrement;
        }

        public static bool operator == (StoreProperties store_1, StoreProperties store_2)
        {
            return store_1.area == store_2.area;
        }

        public static bool operator != (StoreProperties store_1, StoreProperties store_2)
        {
            return store_1.area != store_2.area;
        }

        public static bool operator > (StoreProperties store_1, StoreProperties store_2)
        {
            return store_1.area > store_2.area;
        }

        public static bool operator < (StoreProperties store_1, StoreProperties store_2)
        {
            return store_1.area < store_2.area;
        }

        public override bool Equals(object? obj)
        {
            if (obj == null || obj.GetType() != this.GetType()) 
            {
                return false;
            }

            StoreProperties other = (StoreProperties)obj;
            if (this.area != other.area)
                return false;
            if (this.Name != other.Name)
                return false;
            if (this.Address != other.Address)
                return false;

            return true;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}