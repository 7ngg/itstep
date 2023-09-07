namespace Trading
{
    public class Money {
        public uint Paper { get; set; }
        uint _metal;
        public uint Metal { 
            get => _metal;
            set
            {
                while (value >= 100)
                {
                    value -= 100;
                    Paper += 1;
                }
                _metal = value;
            } 
        }

        public Money() {}
        public Money(uint _paper, uint _metal) 
        {
            while (_metal >= 100)
            {
                _metal -= 100;
                _paper += 1;
            }
            Paper = _paper;
            Metal = _metal;
        }


        public override string ToString()
        {
            return $"Available amount {Paper}.{Metal}";
        }
    }


    public class Product : Money {
        public string Name;


        public void LowerPrice(double amount) {
            if (amount < 0)
            {
                throw new ArgumentException("Invalid argument");
            }
            uint overallMetal = Paper * 100 + Metal;
            amount *= 100;
            overallMetal -= (uint)amount;
            Paper = overallMetal / 100;
            Metal = overallMetal % 100;
        }
    }
}