#include "StateManager.h"
#include "StateSubclass.h"
#include <iostream>

int main() {
    StateManager sm;
    MenuScreen ms(&sm);
    sm.addState(&ms);
    GameState gs(&sm);
    sm.addState(&gs);
    sm.push(1);

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "G-Shift", sf::Style::Close);
    sf::Clock clock;
    float lag = 0;
    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e)) {
            if(e.type==sf::Event::Closed)
                window.close();
        }

        sm.handleInput();
        sm.update(spf);

        window.clear(sf::Color::Black);
        sm.draw(window);
        window.display();

        float timePassed = lag+clock.getElapsedTime().asSeconds();
        if(timePassed<spf) {
            float extra = spf-timePassed;
            sf::sleep(sf::seconds(extra));
            std::cout << extra << std::endl;
            lag = 0;
        } else {
            lag = timePassed-spf;
        }
        clock.restart();
    }
    return 0;
}
