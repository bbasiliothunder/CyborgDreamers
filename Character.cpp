#include "EntitySubclass.h"
#include <SFML/Graphics.hpp>
#include <iostream>

Character::Character(): direction(Movement::STAY), position(sf::Vector2f(16, 16)), lastTic(0), spriteDir(0), spriteAction(0) {
    spriteSheet.loadFromFile("assets/sprites/spritesheet.png");
}

void Character::setDirection(Movement m) {
    if(spriteAction!=0) return;
    direction = m;
    spriteAction = 1;

    if(m==Movement::DOWN) {
        spriteDir = 0;
    } else if(m==Movement::LEFT) {
        spriteDir = 1;
    } else if(m==Movement::RIGHT) {
        spriteDir = 2;
    } else if(m==Movement::UP) {
        spriteDir = 3;
    }
    lastTic = 4;

    //std::cout << "test: " << spriteAction << spriteDir  << std::endl;
}

void Character::update(float dt) {

    if(spriteAction!=0) {
        if(direction==Movement::DOWN) {
            position += sf::Vector2f(0, 4);
        } else if(direction==Movement::LEFT) {
            position += sf::Vector2f(-4, 0);
        } else if(direction==Movement::RIGHT) {
            position += sf::Vector2f(4, 0);
        } else if(direction==Movement::UP) {
            position += sf::Vector2f(0, -4);
        }
    }

    if(lastTic>0) {
        lastTic--;
        if(lastTic>0) return;
    }
    lastTic = 4;

    if(spriteAction==1) {
        spriteAction = 2;
        return;
    }

    spriteAction = 0;
    direction = Movement::STAY;
}

void Character::draw(sf::RenderWindow& window) const {
    sf::Sprite toRender(spriteSheet, sf::IntRect(spriteAction*32, spriteDir*32, 32, 32));
    toRender.setOrigin(16, 16);
    toRender.setPosition(position);
    window.draw(toRender);
}
