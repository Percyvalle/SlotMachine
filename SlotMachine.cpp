#include "SlotMachine.h"

#include "WaitingState.h"

using namespace sf;

SlotMachine::SlotMachine()
{
    m_settings.antialiasingLevel = 8;

    m_mainWindow = new RenderWindow(VideoMode(880, 420), "SlotMachine", Style::Close, m_settings);
    m_mainWindow->setFramerateLimit(30);
    
    m_eventHandler = new Event;
    m_roll_machine = new RollMachine(m_mainWindow);
    m_state = new WaitingState;

    initUI();
}

SlotMachine::~SlotMachine()
{
    delete start_button;
    delete stop_button;
    delete m_mainWindow;
    delete m_roll_machine;
    delete m_eventHandler;
    delete m_state;
}


void SlotMachine::run() {
    m_button_list.push_back(start_button);
    m_button_list.push_back(stop_button);

    while (m_mainWindow->isOpen())
    {
        m_mainWindow->clear(Color::White);

        while (m_mainWindow->pollEvent(*m_eventHandler))
        {
            if (m_eventHandler->type == Event::Closed)
                m_mainWindow->close();

            for (Button *button : m_button_list) {
                if (IntRect(button->getRect()).contains(Mouse::getPosition(*m_mainWindow))) {
                    button->setColor(Color(89, 89, 89));
                    button->setIsHover(1);
                }
                else {
                    button->setColor(Color::Black);
                    button->setIsHover(0);
                }
            }
        }

        handlerInput();
        buttonDraw();
        m_roll_machine->draw();

        text_result.setString("Result: " + std::to_string(result));
        m_mainWindow->draw(text_result);
        m_mainWindow->draw(text_state);
        m_mainWindow->draw(text_win);
        m_mainWindow->display();
    }
}

void SlotMachine::initUI() {
    start_button = new Button(Vector2f(680, 50), Vector2f(150, 55), Color::Black, "Start", m_mainWindow);
    stop_button = new Button(Vector2f(680, 342), Vector2f(150, 55), Color::Black, "Stop", m_mainWindow);

    font.loadFromFile("pico-8.ttf");

    text_result.setFont(font);
    text_result.setPosition(Vector2f(680, 300));
    text_result.setStyle(sf::Text::Bold);
    text_result.setCharacterSize(18);
    text_result.setFillColor(Color::Black);

    text_win.setFont(font);
    text_win.setPosition(Vector2f(680, 270));
    text_win.setStyle(sf::Text::Bold);
    text_win.setCharacterSize(18);
    text_win.setFillColor(Color::Black);

    text_state.setFont(font);
    text_state.setPosition(Vector2f(40, 20));
    text_state.setStyle(sf::Text::Bold);
    text_state.setCharacterSize(18);
    text_state.setFillColor(Color::Black);
}

void SlotMachine::handlerInput() {
    State* state = m_state->handlerInput(*this);
    if (state != NULL) {
        delete m_state;
        m_state = state;
    }
}

void SlotMachine::buttonDraw() {
    for (Button* button : m_button_list) {
        button->draw();
    }
}
