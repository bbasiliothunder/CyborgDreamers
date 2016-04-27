#include "StateManager.h"
#include "Splash.h"
#include "MenuState.h"
#include "GameState.h"
#include "Universal.h"

int main() {
    StateManager sm;
    Splash s(&sm); // 0
    MenuState ms(&sm); // 1
    GameState gs(&sm); // 2

    sm.addState(&s);
    sm.addState(&ms);
    sm.addState(&gs);
    sm.push(0);
    sf::RenderWindow window(sf::VideoMode(Universal::window_width, Universal::window_height), "G-Shift", sf::Style::Close);
    sf::Clock clock;
    float lag = 0;
    while(window.isOpen())
    {
        sf::Event e;
        std::string typed = "";
        while(window.pollEvent(e)) {
            if(e.type==sf::Event::Closed)
                window.close();
            else if(e.type==sf::Event::TextEntered && e.text.unicode<128) {
                typed += static_cast<char>(e.text.unicode);
            }
        }

        sm.handleInput(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y, typed);
        sm.update(Universal::spf);

        window.clear(sf::Color::Black);
        sm.draw(window);
        window.display();

        float timePassed = lag+clock.getElapsedTime().asSeconds();
        if(timePassed<Universal::spf) {
            float extra = Universal::spf-timePassed;
            sf::sleep(sf::seconds(extra));
            lag = 0;
        } else {
            lag = timePassed-Universal::spf;
        }
        clock.restart();
    }
    return 0;
}
