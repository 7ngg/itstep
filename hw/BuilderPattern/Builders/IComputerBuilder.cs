namespace BuilderPattern.Builders
{
    public interface IComputerBuilder
    {
        public string GetMotherboard();
        public string InsertCPU();
        public string InsertRam();
        public string InsertGpu();
        public bool ConnectPowerCables();
        public int ConnectStorage();
    }
}