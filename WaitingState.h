#pragma once

#include "Button.h"
#include "State.h"
#include "RollState.h"
#include "SlotMachine.h"

/*!
	\brief ��������� �������� ������� (������ ���������)
*/
class WaitingState : public State
{
public:
	WaitingState();
	~WaitingState();

	State* handlerInput(SlotMachine& _slotMachine) override;
};

