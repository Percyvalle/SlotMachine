#include "VictoryState.h"
#include <iostream>

VictoryState::VictoryState() {
}

VictoryState::~VictoryState() {

}

State* VictoryState::handlerInput(SlotMachine& _slotMachine) {
    
    _slotMachine.setTextState("Victory");

    _slotMachine.plusResult(_slotMachine.getRollMachine()->getResult());
    _slotMachine.getRollMachine()->restart();
    _slotMachine.restartTimer();

    return new WaitingState();
}