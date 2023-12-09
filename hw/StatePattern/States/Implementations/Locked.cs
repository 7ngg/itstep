namespace StatePattern.States.Implementations
{
    public class Locked : IState
    {
        public void ButtonPress()
        {
            System.Console.WriteLine("Locked screen");
        }
    }
}