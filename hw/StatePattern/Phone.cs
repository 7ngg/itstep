using StatePattern.States;

namespace StatePattern
{
    public class Phone
    {
        private IState _state;

        public Phone(IState state = null)
        {
            _state = state;
        }

        public void SetState(IState state)
        {
            _state = state;
        }

        public void ButtonPress()
        {
            _state.ButtonPress();
        }
    }
}