namespace BuilderPattern.Entities
{
    public class ComputerModel
    {
        public string Motherboard { get; set; }
        public string CPU { get; set; }
        public string GPU { get; set; }
        public string RAM { get; set; }
        public int Storages { get; set; }
        public bool IsPowerConnected { get; set; }

        public override string ToString()
        {
            string power = IsPowerConnected ? "On" : "Off";
            return $"Motherboard: {Motherboard}\nCPU: {CPU}\nGPU: {GPU}\nRAM: {RAM}\nStorages: {Storages}\nPower: {power}";
        }
    }
}