#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

using namespace sf;

/*!
	\brief ����� ��� ���������� ��������
*/
class Roll 
{
public:
	Roll(Vector2i _position);
	~Roll();

	/*!
	* ����� ��������
	*/
	void run(RenderWindow* _window, bool& isStart, bool& isStop);

	/*!
	* �������� ������� ��� ������ �� ������� �������������� ������
	* 
	* ���� = 30
	* ����������� = 3
	* ���� = 4
	* ��� ������� �� ���������� ����� �� ������
	*/
	int getFigure();
	int getSpeedRoll() { return m_speed_roll; }
	bool getIsStopping() { return m_stopping;  }
	void generateFigure();

private:
	int m_max_time;
	int m_speed_roll;
	int m_x_position;
	int m_y_position = 50;
	int m_x_position_figure;
	int m_y_position_figure = 50;
	bool m_stopping = false;
	Clock m_timer;
	RectangleShape m_roll;
	RectangleShape m_wall_top;
	RectangleShape m_wall_bottom;

	std::list<Shape*> remove_list;
	std::list<Shape*> m_list_rand_figure;
};