namespace BusStopHW.Entities
{
    public class Bus
    {
        public int CurrentCount { get; set; } 
        public int Capacity { get; set; } 
    
        public void GetPassengers(BusStop busStop)
        {
            busStop.CurrentCount -= Capacity - CurrentCount;
            CurrentCount = Capacity;
        }

        public void DropPassengers(int count = 0)
        {
            if (count == 0) count = Capacity;
            CurrentCount -= count;
        }
    }
}
