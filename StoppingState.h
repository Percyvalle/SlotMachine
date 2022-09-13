#pragma once

#include "State.h"
#include "VictoryState.h"
#include "SlotMachine.h"

/*!
	\brief Состояние остановки барабана (Машина состояния)
*/
class StoppingState : public State
{
public:
	StoppingState();
	~StoppingState();

	State* handlerInput(SlotMachine& _slotMachine) override;
};

