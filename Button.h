#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

/*!
	\brief Класс реализации кнопочного элемента
*/
class Button
{
public:
	Button(const Vector2f &_position,const Vector2f &_size,const Color &_color, const String& _text, RenderWindow *_window);
	~Button();

	const void draw();

	const Rect<int> getRect();
	void setColor(const Color& _color);

	const int getIsHover();
	void setIsHover(const int &_hover);

private:
	RectangleShape m_button;
	RenderWindow *m_window;
	Vector2f m_position;
	Vector2f m_size;
	String m_text;
	Color m_color;
	Font m_font;
	Text m_title;
	int isHover;
};

