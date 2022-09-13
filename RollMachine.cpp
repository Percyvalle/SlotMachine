#include "RollMachine.h"
#include <iostream>

RollMachine::RollMachine(RenderWindow* _window) {
    m_window = _window;
    if (m_roll_list.size() != 0) {

        m_roll_list.clear();
    }

    int x_roll = 40;
    while (m_roll_list.size() < 5) {
        Roll* roll = new Roll(Vector2i(x_roll, 50));
        m_roll_list.push_back(roll);
        x_roll += 125;
    }
}

RollMachine::~RollMachine() {
}

void RollMachine::draw()
{
    for (Roll* roll : m_roll_list) {
        roll->run(m_window,isStart, isStop);
    }
}

void RollMachine::restart() {
    isStart = false;
    isStop = false;

    for (Roll* roll : m_roll_list) {
        roll->generateFigure();
    }
}

int RollMachine::getResult() {
    int result = 0;
    for (Roll* roll : m_roll_list) {
        result += roll->getFigure();
    }

    return result;
}

bool RollMachine::getStoppingSlot() {

    for (Roll* roll : m_roll_list) {
        if (!roll->getIsStopping()) {
            return false;
        }
    }

    return true;
}
