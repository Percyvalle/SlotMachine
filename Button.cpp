#include "Button.h"

Button::Button(const Vector2f & _position, const Vector2f & _size, const Color & _color, const String& _text, RenderWindow* _window)
{
	m_window = _window;
	m_position = _position;
	m_size = _size;
	m_text = _text;
	m_color = _color;

	m_button.setSize(m_size);
	m_button.setPosition(m_position);
	m_button.setFillColor(m_color);
	m_button.setOutlineThickness(2);
	m_button.setOutlineColor(Color::Black);

	m_font.loadFromFile("pico-8.ttf");

	m_title.setFont(m_font);
	m_title.setString(m_text);
	m_title.setPosition(Vector2f(m_position.x + 32, m_position.y + 18));
	m_title.setStyle(sf::Text::Bold);
	m_title.setCharacterSize(18);
}

Button::~Button()
{
}

const void Button::draw()
{
	m_window->draw(m_button);
	m_window->draw(m_title);
}

const Rect<int> Button::getRect()
{
	return Rect<int>(m_position.x, m_position.y, m_size.x, m_size.y);
}

void Button::setColor(const Color& _color)
{
	m_button.setFillColor(_color);
}

const int Button::getIsHover() {
	return isHover;
}

void Button::setIsHover(const int& _hover) {
	isHover = _hover;
}
