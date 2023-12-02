namespace BuilderPattern.Builders.Implementations
{
    public class GamingComputerBuilder : IComputerBuilder
    {
        public bool ConnectPowerCables() => true;

        public int ConnectStorage() => 2;

        public string GetMotherboard() => "GamingPC motherboard";

        public string InsertCPU() => "GamingPC CPU";

        public string InsertGpu() => "GamingPC GPU";

        public string InsertRam() => "GamingPC RAM";
    }
}