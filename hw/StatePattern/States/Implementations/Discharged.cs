namespace StatePattern.States.Implementations
{
    public class Discharged : IState
    {
        public void ButtonPress()
        {
            System.Console.WriteLine("Discharged screen");
        }
    }
}