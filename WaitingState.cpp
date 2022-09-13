#include "WaitingState.h"

WaitingState::WaitingState() : State()
{
}

WaitingState::~WaitingState()
{
}

State* WaitingState::handlerInput(SlotMachine& _slotMachine)
{
    _slotMachine.setTextState("Waiting");
    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (_slotMachine.getStartButton()->getIsHover() && _slotMachine.getTimer().getElapsedTime().asSeconds() > 0.5) {
            _slotMachine.getRollMachine()->start();
            _slotMachine.restartTimer();
            return new RollState();
        }
    }

    return NULL;
}
