#include "StateSubclass.h"
#include "StateManager.h"
#include "Button.h"
#include "Universal.h"
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>



MenuScreen::MenuScreen(StateManager* sm) : sm(sm)
{

}

void MenuScreen::update(float dt)
{

}

void MenuScreen::draw(sf::RenderWindow& window) const
{
    sf::Sprite gameLogo;
	gameLogo.setTexture(logoTexture);
    gameLogo.setPosition(100, 150);

    window.draw(gameLogo);

    sf::Text join;
    join.setPosition(window_width /2, window_height/2 + 100);
    join.setString("Join Game");
    join.setColor(sf::Color::White);

    sf::Text host;
    host.setPosition(window_width /2, window_height/2 + 100);
    host.setString("Host Game");
    host.setColor(sf::Color::White);

    sf::Text opt;
    opt.setPosition(window_width /2, window_height/2 + 100);
    opt.setString("Options");
    opt.setColor(sf::Color::White);
}

