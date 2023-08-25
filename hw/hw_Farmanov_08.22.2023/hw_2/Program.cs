using System.Net;

int taskChoice;

System.Console.Write("Choose task: ");
taskChoice = int.Parse(Console.ReadLine());

switch (taskChoice)
{
    case 1:
    {
        Random random = new Random();
        int[] linear = new int[5];
        int[,] twoDimensional = new int[3, 4];

        for (int i = 0; i < linear.Length; i++)
        {
            Console.Write($"Element {i + 1}: ");
            linear[i] = int.Parse(Console.ReadLine());
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                twoDimensional[i, j] = random.Next(10);
            }
        }

        System.Console.Write("A - ");
        foreach (var item in linear)
        {
            System.Console.Write($"{item} ");
        }

        System.Console.WriteLine();
        Console.WriteLine("B - ");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                Console.Write($"{twoDimensional[i, j]} ");
            }
            System.Console.WriteLine();
        }

        int[] minimalElements = new int[2] {linear.Min(), twoDimensional.Cast<int>().Min()};
        int[] maximalElements = new int[2] {linear.Max(), twoDimensional.Cast<int>().Max()};
        System.Console.WriteLine($"Minimal element of both arrays - {minimalElements.Min()}");
        System.Console.WriteLine($"Maximal element of both arrays - {maximalElements.Max()}");
        System.Console.WriteLine($"Sum of two arrays - {linear.Sum() + twoDimensional.Cast<int>().Sum()}");

        long multiplication = 1;
        foreach (var item in linear)
        {
            multiplication *= item;
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                multiplication *= twoDimensional[i, j];
            }
        }
        System.Console.WriteLine($"Multiplication - {multiplication}");

        System.Console.WriteLine($"Sum of even elements in A - {linear.Where(i => i % 2 == 0).Sum()}");
        System.Console.WriteLine($"Sum of odd elements in B - {twoDimensional.Cast<int>().Where(i => i % 2 == 0).Sum()}");

        break;
    }

    case 2:
    {
        int[,] arr = new int[5, 5];
        int result = 0;
        Random random= new();

        System.Console.WriteLine("Array: ");
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                arr[i, j] = random.Next(-100, 100);
                System.Console.Write($"{arr[i, j]} ");
            }
            System.Console.WriteLine();
        }

        for (int i = arr.Cast<int>().Min(); i < arr.Cast<int>().Max(); i++)
        {
            result += i;
        }
        System.Console.WriteLine($"Sum in range min, max - {result}");

        break;
    }

    case 3:
    {
        string str;
        int key;

        System.Console.Write("String: ");
        str = Console.ReadLine();
        System.Console.Write("Key: ");
        key = int.Parse(Console.ReadLine());

        string encrypted = CaesarEncrypt(str, key);
        string decrypted = CaesarDecrypt(encrypted, key);

        System.Console.WriteLine($"Encrypted: {encrypted}");
        System.Console.WriteLine($"Decrypted: {decrypted}");

        break;
    }

    case 4:
    {
        
    }
}


static char encryptLetter(char letter, int key) {
    if (!char.IsLetter(letter))
    {
        return letter;
    }

    char charStartPoint = char.IsUpper(letter) ? 'A' : 'a';
    letter = (char)(((letter + key - charStartPoint) % 26) + charStartPoint);
    return letter;
}


static string CaesarEncrypt(string str, int key) {
    string result = string.Empty;

    foreach (var item in str)
    {
        result += encryptLetter(item, key);
    }

    return result;
}


static string CaesarDecrypt (string str, int key) {
    return CaesarEncrypt(str, 26 - key);
}