namespace BuilderPattern.Builders.Implementations
{
    public class DesignerComputerBuilder : IComputerBuilder
    {
        public bool ConnectPowerCables() => true;

        public int ConnectStorage() => 3;

        public string GetMotherboard() => "DesignerPC motherboard";

        public string InsertCPU() => "DesignerPC CPU";

        public string InsertGpu() => "DesignerPC GPU";

        public string InsertRam() => "DesignerPC RAM";
    }
}