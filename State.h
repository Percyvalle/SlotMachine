#pragma once

#include <SFML/Graphics.hpp>


/*!
	\brief �����-��������� ��� ��������� ��������� �������� 
*/
class SlotMachine;
class State
{
public:
	State() {}
	~State() {}

	virtual State* handlerInput(SlotMachine& _slotMachine) = 0;
}; 

