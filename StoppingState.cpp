#include "StoppingState.h"

StoppingState::StoppingState() {

}

StoppingState::~StoppingState() {

}

State* StoppingState::handlerInput(SlotMachine& _slotMachine) {
	_slotMachine.setTextState("Stopping");
	if (_slotMachine.getRollMachine()->getStoppingSlot()) {
		return new VictoryState;
	}

	return NULL;
}