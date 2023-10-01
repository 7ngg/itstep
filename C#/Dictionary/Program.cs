using System.Reflection;
using include.Dictionary;


var dictionaries = new List<MyDictionary>();
MyDictionary activeDictionary = new();
string? path = Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location);
string[] files = Directory.GetFiles(path ?? throw new ArgumentNullException(nameof(path)));
int choice = 0;

foreach (string item in files)
{
    MyDictionary tmp = MyDictionary.Deserialize(item);
    if (tmp != null)
    {
        dictionaries.Add(tmp);
    }
}

if (dictionaries.Any())
{
    Console.WriteLine("0. Continue");
    for (int i = 0; i < dictionaries.Count; i++)
    {
        Console.WriteLine($"{i + 1}. {dictionaries[i].Name}");
    }
    Console.Write("Select dictionary: ");
    choice = Convert.ToInt32(Console.ReadLine());
    
    if (choice > 0 && choice < dictionaries.Count)
    {
        activeDictionary = dictionaries[choice - 1];
    } 
}

if (choice == 0 || !dictionaries.Any())
{
    while (true)
    {
        Console.WriteLine("No dictionaries found/selected, creating a new one...");
        Console.Write("Dictionary name: ");
        string dictionaryName = Console.ReadLine() ?? "Untitled dictionary";

        try
        {
            activeDictionary = new MyDictionary(dictionaryName);
            dictionaries.Add(activeDictionary);
            break;
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}


bool flag = true;
while (flag)
{
    System.Console.Write(
        "0. Exit\n" +
        "1. Add new word\n" +
        "2. Edit word\n" +
        "3. Edit translation\n" +
        "4. Remove word\n" +
        "5. Remove translation\n" +
        "6. Search translation\n" +
        "7. Export word to file\n" +
        "8. Export active dictionary to file\n" +
        "9. Print\n" +
        "> "
    );
    choice = Convert.ToInt32(Console.ReadLine());

    switch (choice)
    {
        case 0:
            flag = false;
            break;

        case 1:
        {
            Console.Write("Word: ");
            string key = Console.ReadLine();
            Console.Write("Translation: ");
            string value = Console.ReadLine();

            try
            {
                activeDictionary.Add(key, value);
            }
            catch (Exception ex)
            {
                System.Console.WriteLine(ex.Message);
            }

            break;
        }

        case 2:
        {
            System.Console.Write("Word to edit: ");
            string oldKey = Console.ReadLine();
            System.Console.Write("New word: ");
            string newKey = Console.ReadLine();

            activeDictionary.EditKey(oldKey, newKey);
            
            break;
        }

        case 3:
        {
            System.Console.Write("Translation to edit: ");
            string oldValue = Console.ReadLine();
            System.Console.Write("New translation: ");
            string newValue = Console.ReadLine();

            activeDictionary.EditValue(oldValue, newValue);

            break;
        }

        case 4:
        {
            Console.Write("Word to remove: ");
            string key = Console.ReadLine();
            activeDictionary.RemoveKey(key);

            break;
        }

        case 5:
        {
            Console.Write("Translations to remove: ");
            string value = Console.ReadLine();
            activeDictionary.RemoveValue(value);
            
            break;
        }

        case 6:
        {
            Console.Write("Search word: ");
            string key = Console.ReadLine();
            activeDictionary.PrintAllTranslations(key);

            break;
        }

        case 7:
        {
            Console.Write("Word: ");
            string key = Console.ReadLine();
            activeDictionary.ExportKey(key);
            break;
        }

        case 8:
        {
            MyDictionary.Serialize(activeDictionary);
            break;
        }

        case 9:
        {
            System.Console.WriteLine(activeDictionary);
            break;
        }
    }
}


System.Console.ReadLine();