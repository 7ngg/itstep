namespace Calc
{
    public partial class Form1 : Form
    {
        private double _firstNum = 0;
        private double _secondNum = 0;
        private List<Node> Nums = new();

        public Form1()
        {
            InitializeComponent();
            MainTextBox.Text = "0";
        }


        private void AddNumber(int num)
        {
            if (MainTextBox.Text == "0")
            {
                MainTextBox.Text = num.ToString();
            }
            else
            {
                MainTextBox.Text += num.ToString();
            }
        }


        public double CalculateList()
        {
            double result = Nums[0].Value;

            for (int i = 0; i < Nums.Count - 1; i++)
            {
                result = Nums[i].Operation switch
                {
                    "+" => result + Nums[i + 1].Value,
                    "-" => result - Nums[i + 1].Value,
                    "*" => result * Nums[i + 1].Value,
                    "/" => result / Nums[i + 1].Value
                };
            }

            return result;
        }


        private void button1_Click(object sender, EventArgs e)
        {
            AddNumber(1);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            AddNumber(2);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            AddNumber(3);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            AddNumber(4);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            AddNumber(5);
        }

        private void button6_Click(object sender, EventArgs e)
        {
            AddNumber(6);
        }

        private void button7_Click(object sender, EventArgs e)
        {
            AddNumber(7);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            AddNumber(8);
        }

        private void button9_Click(object sender, EventArgs e)
        {
            AddNumber(9);
        }

        private void button0_Click(object sender, EventArgs e)
        {
            AddNumber(0);
        }

        private void PlusButton_Click(object sender, EventArgs e)
        {
            Nums.Add(new Node(Convert.ToDouble(MainTextBox.Text), "+"));
            MainTextBox.Clear();
        }

        private void MinusButton_Click(object sender, EventArgs e)
        {
            Nums.Add(new Node(Convert.ToDouble(MainTextBox.Text), "-"));
            MainTextBox.Clear();
        }

        private void MultiplyButton_Click(object sender, EventArgs e)
        {
            Nums.Add(new Node(Convert.ToDouble(MainTextBox.Text), "*"));
            MainTextBox.Clear();
        }

        private void DivideButton_Click(object sender, EventArgs e)
        {
            Nums.Add(new Node(Convert.ToDouble(MainTextBox.Text), "/"));
            MainTextBox.Clear();
        }

        private void ClearButton_Click(object sender, EventArgs e)
        {
            MainTextBox.Clear();
            MainTextBox.Text = "0";
        }

        private void DotButton_Click(object sender, EventArgs e)
        {
            if (MainTextBox.Text.Split(',').Length > 1)
            {
                return;
            }
            else
            {
                MainTextBox.Text += ",";
            }
        }

        private void EqualsButton_Click(object sender, EventArgs e)
        {
            Nums.Add(new Node(Convert.ToDouble(MainTextBox.Text), string.Empty));
            MainTextBox.Text = CalculateList().ToString();
            Nums.Clear();
        }
    }
}