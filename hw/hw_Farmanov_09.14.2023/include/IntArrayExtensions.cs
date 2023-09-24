namespace Include.IntArrayExtensions
{
    static public class IntArrayExtensons
    {
        static private List<int> BuildFibonacciSequence(int upperLimit)
        {
            var fibonacciSequence = new List<int>() { 0, 1 };
            for (int i = 2; fibonacciSequence.Last() < upperLimit; ++i)
            {
                fibonacciSequence.Add(fibonacciSequence[i - 1] + fibonacciSequence[i - 2]);
            }
            return fibonacciSequence;
        }

        
        public static int[] GetAllEven(this int[] arr)
        {
            Predicate<int> IsEven = (int x) => x % 2 == 0;
            return arr.Where(x => IsEven(x)).ToArray();
        }


        public static int[] GetAllOdd(this int[] arr)
        {
            Predicate<int> IsOdd = (int x) => x % 2 == 1;
            return arr.Where(x => IsOdd(x)).ToArray();
        }


        public static int[] GetAllPrime(this int[] arr)
        {
            Predicate<int> IsPrime = (int x) => 
            {
                for (int i = 2; i < x / 2 + 1; i++)
                {
                    if (x % i == 0)
                    {
                        return false;
                    }
                }

                return true;
            };

            return arr.Where(x => IsPrime(x)).ToArray();
        }


        public static int[] GetAllFibonacci(this int[] arr)
        {
            Predicate<int> IsFibonacci = (int x) =>
            {
                if (BuildFibonacciSequence(x).Contains(x))
                    return true;
                return false;
            };

            return arr.Where(x => IsFibonacci(x)).ToArray();
        }
    }
}