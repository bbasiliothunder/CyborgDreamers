#include "Universal.h"
#include "StateSubclass.h"
#include "StateManager.h"
#include <iostream>
#include <sstream>


JoinState::JoinState(StateManager *sm){

    font.loadFromFile("assets/fonts/black_jack.ttf");
}

void JoinState::update(float dt)
{
    if(cover==0) return;
    int temp = cover - (255*dt);
    cover = std::max(temp, 0);
}

void JoinState::handleInput(int u, int v)
{
    if(cover>0)
    {
        cover = 0;
        std::cout<<"NADA"<<std::endl;
        return;
    }
    else if(back.checkCollision(u, v))
    {
        std::cout<<"BACK"<<std::endl;
        std::cout<<sf::Mouse::getPosition().y<<std::endl;
    }
}

void JoinState::draw(sf::RenderWindow &window) const
{
    back.draw(window);

    if(cover==0) return;
    sf::Vector2f curtainSize(800, 600);
    sf::RectangleShape curtain(curtainSize);
    curtain.setPosition(0, 0);
    curtain.setFillColor(sf::Color(0, 0, 0, cover));
    window.draw(curtain);
}
