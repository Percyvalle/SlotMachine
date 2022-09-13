#pragma once

#include "Button.h"
#include "State.h"
#include "RollState.h"
#include "SlotMachine.h"

/*!
	\brief Состояние ожидания события (Машина состояния)
*/
class WaitingState : public State
{
public:
	WaitingState();
	~WaitingState();

	State* handlerInput(SlotMachine& _slotMachine) override;
};

