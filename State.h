#pragma once

#include <SFML/Graphics.hpp>


/*!
	\brief Класс-интерфейс для состояний конечного автомата 
*/
class SlotMachine;
class State
{
public:
	State() {}
	~State() {}

	virtual State* handlerInput(SlotMachine& _slotMachine) = 0;
}; 

