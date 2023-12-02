using BuilderPattern.Builders;

namespace BuilderPattern.Entities
{
    public static class ComputerDirector
    {
        public static ComputerModel ConstructComputer(IComputerBuilder builder)
        {
            return new ComputerModel()
            {
                Motherboard = builder.GetMotherboard(),
                CPU = builder.InsertCPU(),
                RAM = builder.InsertRam(),
                GPU = builder.InsertGpu(),
                Storages = builder.ConnectStorage(),
                IsPowerConnected = builder.ConnectPowerCables()  
            };            
        }
    }
}