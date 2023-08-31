using System.Text;

namespace ExtensionMethods
{   
    static class IntExtesions {
        public static bool palindromeCheck(this int num) {
            int length = num.ToString().Length; 
            
            if (length % 2 != 0)
            {
                return false;
            }

            StringBuilder rear = new(), front = new();
            for (int i = 0; i < length / 2; i++)
            {
                front.Append(num.ToString()[i]);
                rear.Append(num.ToString()[length - i - 1]);
            }

            if (rear.ToString() == front.ToString())
            {
                return true;
            }
            return false;
        }
    }


    static class ListExtensionss {
        public static void RemoveBanElements(this List<int> myList, List<int> banElements) {
            myList.Remove;
        }
    }
}