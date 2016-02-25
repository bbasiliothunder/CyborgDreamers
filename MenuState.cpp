#include "Universal.h"
#include "StateSubclass.h"
#include "StateManager.h"
#include <iostream>


MenuState::MenuState(StateManager *sm){

    join.setContent("Join Game");
    join.setPosition(window_width/2 - 10, window_height/2 + 100);
    join.setDimension(200, 40);

    host.setContent("Host Game");
    host.setPosition(window_width/2 - 10, window_height/2 + 150);
    host.setDimension(200, 40);

    options.setContent("Options");
    options.setPosition(window_width/2 - 10, window_height/2 + 200);
    options.setDimension(200, 40);

    cover = 255;
}

void MenuState::update(float dt)
{
    if(cover==0) return;
    int temp = cover - (255*dt);
    cover = std::max(temp, 0);
}

void MenuState::handleInput(int u, int v)
{
    if(cover>0)
    {
        cover = 0;
        std::cout<<"NADA"<<std::endl;
        return;
    }
    else if(join.checkCollision(u, v))
    {
        std::cout<<"JOIN"<<std::endl;
        std::cout<<sf::Mouse::getPosition().y<<std::endl;
    }
    else if(host.checkCollision(u, v))
    {
        std::cout<<"HOST"<<std::endl;
        std::cout<<sf::Mouse::getPosition().y<<std::endl;
    }
    else if(options.checkCollision(u, v))
    {
        std::cout<<"OPTIONS"<<std::endl;
        std::cout<<sf::Mouse::getPosition().y<<std::endl;
    }
}

void MenuState::draw(sf::RenderWindow &window) const
{
    join.draw(window);
    host.draw(window);
    options.draw(window);

    if(cover==0) return;
    sf::Vector2f curtainSize(800, 600);
    sf::RectangleShape curtain(curtainSize);
    curtain.setPosition(0, 0);
    curtain.setFillColor(sf::Color(0, 0, 0, cover));
    window.draw(curtain);
}
