#include "StateManager.h"
#include "TestState.cpp"

int main() {
    int window_width = 800;
    int window_height = 600;
    float fps = 30.0;
    float spf = 1.0/fps;

    TestState state0;

    StateManager sm;
    sm.addState(&state0);
    sm.push(0);

    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "G-Shift");
    sf::Clock clock;
    float lag = 0;
    while(window.isOpen())
    {
        sf::Event e;
        while(window.pollEvent(e)) {
            sm.handleInput(e);
        }

        sm.handleInput(e);
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
