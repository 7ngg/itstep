using System.Collections;
using System.Diagnostics.CodeAnalysis;
using System.Text;

namespace include.Dictionary
{
    public class DictionaryNode<TKey, TValue>
    {
        public TKey Key { get; set; }
        public TValue Value { get; set; }

        public DictionaryNode() {}
        public DictionaryNode(TKey key, TValue value)
        {
            Key = key;
            Value = value;
        }


        public override string ToString()
        {
            return $"{Key} - {Value}";
        }
    }

    class MyDictionary<TKey, TValue>
    {
        public List<DictionaryNode<TKey, TValue>> Dictionary; 
        
#region Constructors

        public MyDictionary() {
            Dictionary = new List<DictionaryNode<TKey, TValue>>();
        }

        public MyDictionary(params DictionaryNode<TKey, TValue>[] nodes)
        {
            Dictionary = new List<DictionaryNode<TKey, TValue>>();
            foreach (var item in nodes)
            {
                if (item != null)
                {
                    Add(item);
                }
            }
        }

#endregion

        public void Add(DictionaryNode<TKey, TValue> arg)
        {
            Dictionary.Add(arg);
        }


        public void Add(TKey key, TValue value)
        {
            if (key != null || value != null)
            {
                Dictionary.Add(new DictionaryNode<TKey, TValue>(key, value));
            }
            else
            {
                throw new ArgumentException("Null passed as method parameter");
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