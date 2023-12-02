namespace BuilderPattern.Builders.Implementations
{
    public class OfficeComputerBuilder : IComputerBuilder
    {
        public bool ConnectPowerCables() => true;

        public int ConnectStorage() => 1;

        public string GetMotherboard() => "OfficePC motherboard";

        public string InsertCPU() => "OfficePC CPU";

        public string InsertGpu() => "OfficePC GPU";

        public string InsertRam() => "OfficePC RAM";
    }
}