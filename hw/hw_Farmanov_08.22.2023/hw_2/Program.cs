using System.Data;
using System.Globalization;
using System.Text;
using System.Text.RegularExpressions;

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

        Console.Write("String: ");
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
        Console.Write("Rows count: ");
        int rows = Convert.ToInt32(Console.ReadLine());
        Console.Write("Columns count: ");
        int columns = Convert.ToInt32(Console.ReadLine());

        int[,] matrix_1 = new int[rows, columns];
        int[,] matrix_2 = new int[columns, rows];
        
        Random random = new();
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                matrix_1[i, j] = random.Next(5);
            }
        }
        for (int i = 0; i < columns; i++)
        {
            for (int j = 0; j < rows; j++)
            {
                matrix_2[i, j] = random.Next(5);
            }
        }

        System.Console.WriteLine("Matrix 1: ");
        printMatrix(matrix_1);
        System.Console.WriteLine("Matrix 2: ");
        printMatrix(matrix_2);

        Console.Write(
            "1. Add matrices\n" +
            "2. Multiply by number\n" +
            "3. Multiply matrices\n" + 
            "> "
        );
        int choice = Convert.ToInt32(Console.ReadLine());

        switch (choice)
        {
            case 1:
            {
                Console.WriteLine("Result");
                printMatrix(addMatrices(matrix_1, matrix_2));
                break;
            }

            case 2:
            {
                Console.Write("Enter multiplier: ");
                int multiplier = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Matrix 1: ");
                printMatrix(multiplyMatrixByNum(matrix_1, multiplier));
                Console.WriteLine("Matrix 2: ");
                printMatrix(multiplyMatrixByNum(matrix_2, multiplier));
                break;
            }

            case 3:
            {
                System.Console.WriteLine("Result: ");
                printMatrix(multiplyMatrix(matrix_1, matrix_2));
                break;
            }

            default:
                break;
        }

        break;
    }

    case 5:
    {
        string expression;

        Console.Write("Expression: ");
        expression = Console.ReadLine();

        var result = new DataTable().Compute(expression, null);
        System.Console.WriteLine($"Result: {result}");

        break;
    }

    case 6:
    {
        Console.WriteLine("Text: ");
        string text = Console.ReadLine();
        StringBuilder result = new();

        string[] sentences = text.Split('.', '!', '?');

        for (int i = 0; i < sentences.Length; i++)
        {
            string sentence = sentences[i].Trim();
            if (!string.IsNullOrEmpty(sentence))
            {
                char[] charStr = sentence.ToCharArray();
                if (char.IsLower(charStr[0]))
                {
                    charStr[0] = char.ToUpper(charStr[0]);
                }
                sentences[i] = new string(charStr);
                result.Append(sentences[i]);
                result.Append(". ");
            }
        }

        System.Console.WriteLine($"Result:\n {result.ToString()}");

        break;
    }

    case 7:
    {
        System.Console.WriteLine("Text: ");
        string text = Console.ReadLine();
        System.Console.Write("Banword: ");
        string banWord = Console.ReadLine();

        string result = Regex.Replace(text, banWord, "****", RegexOptions.IgnoreCase);
        int count = Regex.Count(text, banWord);

        System.Console.WriteLine(result);
        System.Console.WriteLine($"Replaced times: {count}");

        break;
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


static void printMatrix(int[,] matrix) {
    int rows = matrix.GetLength(0);
    int columns = matrix.GetLength(1);

    for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                Console.Write($"{matrix[i, j]} ");
            }
            System.Console.WriteLine();
        }
}


static int[,] addMatrices(int[,] matrix_1, int[,] matrix_2) {
    int matrix_1Rows = matrix_1.GetLength(0);
    int matrix_1Columns = matrix_1.GetLength(1);
    int matrix_2Rows = matrix_2.GetLength(0);
    int matrix_2Columns = matrix_2.GetLength(1);

    if (matrix_1Rows != matrix_2Rows || matrix_1Columns != matrix_2Columns) {
        throw new ArgumentException("Matrices are not compatible");
    }

    int[,] result = new int[matrix_1Rows, matrix_1Columns];

    for (int i = 0; i < matrix_1Rows; i++)
    {
        for (int j = 0; j < matrix_1Columns; j++)
        {
            result[i, j] = matrix_1[i, j] + matrix_2[i, j];
        }
    }

    return result;
}


static int[,] multiplyMatrixByNum(int[,] matrix, int multiplier) {
    int rows = matrix.GetLength(0);
    int columns = matrix.GetLength(1);
    int[,] result = new int[rows, columns];

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result[i, j] = matrix[i, j] * multiplier;
        }
    }

    return result;
}


static int[,] multiplyMatrix(int[,] matrix_1, int[,] matrix_2) {
    int matrix_1Rows = matrix_1.GetLength(0);
    int matrix_1Columns = matrix_1.GetLength(1);
    int matrix_2Rows = matrix_2.GetLength(0);
    int matrix_2Columns = matrix_2.GetLength(1);

    if (matrix_1Rows != matrix_2Columns)
    {
        throw new ArgumentException("Matrices are not compatible");
    }
    
    int[,] result = new int[matrix_1Rows, matrix_2Columns];
    for (int i = 0; i < matrix_1Rows; i++)
    {
        for (int j = 0; j < matrix_2Columns; j++)
        {
            int tmpValue = 0;
            for (int k = 0; k < matrix_1Columns; k++)
            {
                tmpValue += matrix_1[i, k] * matrix_2[k, j];
            }
            result[i, j] = tmpValue;
        }
    }

    return result;
}