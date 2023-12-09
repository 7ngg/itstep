namespace StatePattern.States.Implementations
{
    public class On : IState
    {
        public void ButtonPress()
        {
            System.Console.WriteLine("Functioning screen");
        }
    }
}