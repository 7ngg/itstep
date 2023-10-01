using System.Collections.Concurrent;
using System.Net;
using System.Text;
using System.Text.Json;
using Exceptions;

namespace include.Dictionary
{
    public class DictionaryNode
    {
        public string Key { get; set; }
        public string Value { get; set; }

        public DictionaryNode() {
            Key = string.Empty;
            Value = string.Empty;
        }
        public DictionaryNode(string key, string value)
        {
            Key = key;
            Value = value;
        }


        public override string ToString()
        {
            return $"{Key} - {Value}";
        }
    }

    class MyDictionary
    {
        private string _name;
        public string Name
        {
            get { return _name; }
            set 
            {
                if (string.IsNullOrEmpty(value))
                {
                    throw new InvalidDictionaryNameException();
                }

                _name = value;
            }
        }
        public List<DictionaryNode> Dictionary { get; set; }
        
#region Constructors

        public MyDictionary() {}

        public MyDictionary(string name) {
            Name = name;
            Dictionary = new List<DictionaryNode>();
        }

        public MyDictionary(string name, params DictionaryNode[] nodes)
        {
            Name = name;
            Dictionary = new List<DictionaryNode>();
            foreach (var item in nodes)
            {
                if (item != null)
                {
                    Add(item);
                }
            }
        }

#endregion

        public bool ContainsKey(string key)
        {
            return Dictionary.Any(x => x.Key == key);
        }


        public bool ContainsValue(string value)
        {
            return Dictionary.Any(x => x.Value == value);
        }


        public void Add(DictionaryNode arg)
        {
            Dictionary.Add(arg);
        }


        public void Add(string key, string value)
        {
            if (key != null && value != null)
            {
                Dictionary.Add(new DictionaryNode(key, value));
            }
            else
            {
                throw new ArgumentException("Null passed as method parameter");
            }
        }


        public static void Serialize(MyDictionary dictionary)
        {
            using FileStream stream = new(dictionary.Name + ".json", FileMode.OpenOrCreate);
            using StreamWriter writer = new(stream);
            JsonSerializerOptions options = new()
            {
                Encoder = System.Text.Encodings.Web.JavaScriptEncoder.UnsafeRelaxedJsonEscaping,
                WriteIndented = true
            };
            string json = JsonSerializer.Serialize(dictionary, options);
            writer.Write(json);
        }


        public static MyDictionary Deserialize(string fileName)
        {
            MyDictionary? result = null;

            if (fileName.Contains(".json"))
            {
                using FileStream stream = new(fileName, FileMode.Open);
                using StreamReader reader = new(stream);
                string json = reader.ReadToEnd();
                var tmp = JsonSerializer.Deserialize<MyDictionary>(json);
                
                if (tmp != null && !string.IsNullOrEmpty(tmp.Name))
                {
                    result = tmp;
                }
            }

            return result;
        }


        public void EditKey(string oldKey, string newKey)
        {
            if (ContainsKey(oldKey))
            {
                foreach (var item in Dictionary)
                {
                    if (item.Key == oldKey)
                    {
                        item.Key = newKey;
                    }
                }
            }
            else
            {
                System.Console.WriteLine("No such word in current dictionary");
            }
        }


        public void EditValue(string oldValue, string newValue)
        {
            if (ContainsValue(oldValue))
            {
                foreach (var item in Dictionary)
                {
                    if (item.Value == oldValue)
                    {
                        item.Value = newValue;
                    }
                }
            }
            else
            {
                System.Console.WriteLine("No such translation in current dictionary");
            }
        }


        public void PrintAllTranslations(string key)
        {
            System.Console.WriteLine($"{key}: ");
            foreach (var item in Dictionary)
            {
                if (item.Key == key)
                {
                    System.Console.WriteLine($"\t{item.Value}");
                }
            }
        }


        public void RemoveKey(string key)
        {
            Dictionary.RemoveAll(x => x.Key == key);
        }


        public void RemoveValue(string value)
        {
            string key = Dictionary.First(x => x.Value == value).Key;
            int count = Dictionary.Count(x => x.Key == key);
            bool isSingle = count <= 1;

            if (isSingle)
            {
                System.Console.WriteLine("Dictionary contains only one translation of the given word. Removal prohibited");
            }
            else
            {
                DictionaryNode elementToKeep = Dictionary.First(x => x.Key == key && x.Value != value);
                RemoveKey(key);
                Add(elementToKeep);
            }
        }


        public void ExportKey(string key)
        {
            var translatons = Dictionary.Where(x => x.Key == key).ToList();

            if (translatons.Count > 0)
            {
                using FileStream stream = new(key + ".json", FileMode.OpenOrCreate);
                using StreamWriter writer = new(stream);

                JsonSerializer.Serialize(translatons);
                writer.Write(translatons);
            }
            else
            {
                System.Console.WriteLine("No such word in active dictionary");
            }
        }


        public override string ToString()
        {
            var str = new StringBuilder();
            foreach (var item in Dictionary)
            {
                str.AppendLine(item.ToString());
            }

            return str.ToString();
        }
    }
}