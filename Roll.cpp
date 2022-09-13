#include "Roll.h"
#include <iostream>
#include <iterator>

Roll::Roll(Vector2i _position) {
    m_x_position = _position.x;
    m_y_position = _position.y;

    m_roll.setSize(Vector2f(125, 350));
    m_roll.setPosition(Vector2f(m_x_position, m_y_position));
    m_roll.setOutlineThickness(2);
    m_roll.setOutlineColor(Color::Black);
    m_roll.setFillColor(Color(255, 255, 255, 0));

    m_wall_top.setSize(Vector2f(129, 48));
    m_wall_top.setPosition(Vector2f(m_x_position - 2, 0));
    m_wall_top.setFillColor(Color::White);

    m_wall_bottom.setSize(Vector2f(129, 20));
    m_wall_bottom.setPosition(Vector2f(m_x_position - 2, 402));
    m_wall_bottom.setFillColor(Color::White);

    generateFigure();
}

Roll::~Roll() {
}

void Roll::run(RenderWindow* _window, bool& isStart, bool& isStop) {                                    
	_window->draw(m_roll);

    if (isStop && m_speed_roll > 0) {
        m_speed_roll -= 1;
    } else if (m_timer.getElapsedTime().asSeconds() > m_max_time && m_speed_roll > 0) {
        m_speed_roll -= 1;
    }

    for (Shape* figure : m_list_rand_figure) {

        if (m_speed_roll == 0) {
            if (m_list_rand_figure.front()->getPosition().y != 40) {
                if (m_list_rand_figure.front()->getPosition().y < 40) {
                    figure->setPosition(Vector2f(figure->getPosition().x, figure->getPosition().y + 1));
                }
                else {
                    figure->setPosition(Vector2f(figure->getPosition().x, figure->getPosition().y - 1));
                }
            }
            else {
                isStop = true;
                m_stopping = true;
            }

            isStart = false;
        }

        if (isStart || isStop) {
            figure->setPosition(Vector2f(figure->getPosition().x, figure->getPosition().y - m_speed_roll));
        }

        _window->draw(*figure);

        if (figure->getPosition().y < -50) {
            remove_list.push_back(figure);
        }
    }

    for (Shape* remove_figure : remove_list) {
        m_list_rand_figure.remove(remove_figure);
    }

    remove_list.clear();

    _window->draw(m_wall_top);
    _window->draw(m_wall_bottom);
}

int Roll::getFigure() {
    // - Мне кажется, или это костыль 0_-
    // - Тут все костыль
    int count = 0;
    for (Shape* i : m_list_rand_figure) {
        if (count == 1) {
            return i->getPointCount();
        }
        count++;
    }
    return 0;
}

void Roll::generateFigure() {
    m_speed_roll = 60 + rand() % 5;
    m_max_time = 5;

    if ((m_speed_roll % 2) != 0) {
        m_speed_roll += 1;
    }

    m_x_position_figure = m_x_position + 10;

    if (m_list_rand_figure.size() > 0) {
        m_y_position_figure = m_list_rand_figure.back()->getPosition().y + 150;
    }

    Shape* figure = new CircleShape();
    while (m_list_rand_figure.size() < 100) {
        switch (rand() % 3 + 0)
        {
        case 0:
            figure = new CircleShape(45);
            break;
        case 1:
            figure = new CircleShape(55, 3);
            break;
        case 2:
            figure = new CircleShape(50, 4);
            break;
        }

        figure->setFillColor(Color::Black);
        figure->setPosition(Vector2f(m_x_position_figure, m_y_position_figure));
        m_list_rand_figure.push_back(figure);
        m_y_position_figure += 150;
    }
    
    m_stopping = false;
    m_timer.restart();
}