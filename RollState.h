#pragma once

#include "Button.h"
#include "State.h"
#include "SlotMachine.h"
#include "StoppingState.h"

/*!
	\brief Состояние кручение барабанов слот-машины (Машина состояния)
*/
class RollState : public State
{
public:
	RollState();
	~RollState();

	State* handlerInput(SlotMachine& _slotMachine) override;
};