#pragma once

#include "State.h"
#include "WaitingState.h"
#include "SFML/Window.hpp"

using namespace sf;


/*!
	\brief ��������� ����� � �������� ��������� �������� (������ ���������)
*/
class VictoryState : public State
{
public:
	VictoryState();
	~VictoryState();

	State* handlerInput(SlotMachine& _slotMachine) override;

private:
};

