#pragma once

#include <SFML/Graphics.hpp>

#include "RollMachine.h"
#include "Button.h"
#include "Roll.h"
#include "State.h"

#include <iostream>
#include <vector>

using namespace sf;


/*!
	\brief Основной класс реализации слот-машины
*/
class SlotMachine
{
public:
	SlotMachine();
	~SlotMachine();

	/*!
	 *Метод запуска слот-машины
	 */
	void run();

	/*!
	 *Обработка смены состояний
	 */
	void handlerInput();

	/*!
	 * Отрисовка кнопок
	 */
	void buttonDraw();

	Button* getStartButton() const { return start_button; }
	Button* getStopButton() const { return stop_button; }
	RollMachine* getRollMachine() const { return m_roll_machine; }
	
	Clock getTimer() const { return m_timer; }
	void restartTimer() { m_timer.restart(); }

	/*!
	* Метод суммирования результата
	*/
	void plusResult(int _result) { result += _result; }
	void setTextState(String _state) { text_state.setString("State: " + _state); }

private:
	Button* start_button;
	Button* stop_button;
	RenderWindow *m_mainWindow;
	ContextSettings m_settings;
	RollMachine* m_roll_machine;
	Event *m_eventHandler;
	Clock m_timer;
	State* m_state;

	Font font;
	Text text_state;
	Text text_result;
	int result = 0;

	std::vector<Button*> m_button_list;
};

