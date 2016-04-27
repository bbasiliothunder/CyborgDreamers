#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include "StateManager.h"
#include "HostState.h"

HostState::HostState(StateManager* sm): State(sm), sm(sm),
back(sf::Vector2f(Universal::window_width/2.0-250, Universal::window_height/2.0+250), sf::Vector2f(100, 20), "Back"),
players1(sf::Vector2f(Universal::window_width/2.0, Universal::window_height/2.0-75), sf::Vector2f(100, 20), "Solo Game"),
players2(sf::Vector2f(Universal::window_width/2.0, Universal::window_height/2.0-25), sf::Vector2f(100, 20), "2 Players"),
players3(sf::Vector2f(Universal::window_width/2.0, Universal::window_height/2.0+25), sf::Vector2f(100, 20), "3 Players"),
players4(sf::Vector2f(Universal::window_width/2.050, Universal::window_height/2.0+75), sf::Vector2f(100, 20), "4 Players"),
name("Player 1")
{
    font.loadFromFile("assets/fonts/black_jack.ttf");

    nameLabel = sf::Text("Name: ", font);
    nameInput = sf::Text(name, font);

    nameLabel.setPosition(Universal::window_width/2.0 - 80, Universal::window_height/2.0 - 150);
    nameInput.setPosition(Universal::window_width/2.0 + 10, Universal::window_height/2.0 - 150);
}

void HostState::update(float dt) {
    nameInput.setString(name);
}

void HostState::handleInput(int u, int v, const std::string& accept) {
    Universal::appendTextInput(name, accept);
    bool leftClick = sf::Mouse::isButtonPressed(sf::Mouse::Left);
    int playerCap = -1;

    if(back.checkCollision(u, v) && leftClick)
        popSelf(1, "");
    else if(players1.checkCollision(u, v) && leftClick)
        playerCap = 1;
    else if(players2.checkCollision(u, v) && leftClick)
        playerCap = 2;
    else if(players3.checkCollision(u, v) && leftClick)
        playerCap = 3;
    else if(players4.checkCollision(u, v) && leftClick)
        playerCap = 4;

    if(playerCap > 0) {
        char playerString[1];
        itoa( playerCap, playerString, 10 );
        sm->push(4, "host " + std::string(playerString));
    }
}

void HostState::draw(sf::RenderWindow& rw) const {
    back.draw(rw);
    players1.draw(rw);
    players2.draw(rw);
    players3.draw(rw);
    players4.draw(rw);

    rw.draw(nameLabel);
    rw.draw(nameInput);
}
