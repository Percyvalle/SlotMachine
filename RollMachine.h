#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "Roll.h"

using namespace sf;


/*!
	\brief Класс для реализации управления барабанами слот-машины
*/
class RollMachine
{
public:
	RollMachine(RenderWindow *_window);
	~RollMachine();

	void start() { isStart = true; isStop = false; }
	void stop() { isStart = false; isStop = true; }
	void restart();
	void draw();
	bool getIsStop() { return isStop; }
	bool getStoppingSlot();
	int getResult();

private:
	bool isStart = false;
	bool isStop = false;
	RenderWindow *m_window;
	std::vector<Roll*> m_roll_list;
};

