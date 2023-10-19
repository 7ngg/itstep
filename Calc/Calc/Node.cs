using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Calc
{
    public class Node
    {
        public double Value;
        public string Operation;

        public Node()
        {
            Value = 0;
            Operation = string.Empty;
        }

        public Node(double num, string opr)
        {
            Value = num;
            Operation = opr;
        }
    }
}
