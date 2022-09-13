#include "RollState.h"

RollState::RollState() {

}

RollState::~RollState() {

}

State* RollState::handlerInput(SlotMachine& _slotMachine) {

    _slotMachine.setTextState("Roll");
    if (Mouse::isButtonPressed(Mouse::Left)) {
        if (_slotMachine.getStopButton()->getIsHover() && _slotMachine.getTimer().getElapsedTime().asSeconds() > 0.5) {
            _slotMachine.getRollMachine()->stop();
            _slotMachine.restartTimer();

            return new StoppingState();
        }
    }
    else if (_slotMachine.getRollMachine()->getIsStop() == true) {
        return new StoppingState();
    }

    return NULL;
}