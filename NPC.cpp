#include "NPC.h"
#include <SFML/Graphics.hpp>
#include <iostream>

typedef enum
{
    Kid, Look, Go
} aitype1;

NPC::NPC():position(sf::Vector2f(144, 144)), lastTic(0), spriteDir(0), spriteAction(0),fl(FollowerBehavior::getInstance()),
    map(Map("1")), direction(Movement::RIGHT), kb(KidBehavior::getInstance()), la(LookAroundBehavior::getInstance()),
    ga(GoAroundBehavior::getInstance()){
    spriteSheet.loadFromFile("assets/sprites/spritesheet.png");
}

void NPC::setDirection(Movement m) {
    if(spriteAction!=0) return;
    direction = m;
    spriteAction = 1;

    setFace(m);
    lastTic = 4;
}

void NPC::setFace(Movement m) {
    if(m==Movement::DOWN) {
        spriteDir = 0;
    } else if(m==Movement::LEFT) {
        spriteDir = 1;
    } else if(m==Movement::RIGHT) {
        spriteDir = 2;
    } else if(m==Movement::UP) {
        spriteDir = 3;
    }
}

void NPC::update(float dt, Map map, int ai) {

    switch(ai)
    {
        case Kid: kb(this, dt, map);
            break;
        case Look: la(this, dt, map);
            break;
        case Go: ga(this, dt, map);
            break;
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
    //direction = Movement::STAY;
}

void NPC::update(float dt, Map map, sf::Vector2f chars, Movement charsm, Character *chars2) {

    fl(this, dt, map, chars, charsm, chars2);

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
    //direction = Movement::STAY;
}

void NPC::update(float dt)
{

}

void NPC::draw(sf::RenderWindow& window) const {
    sf::Sprite toRender(spriteSheet, sf::IntRect(spriteAction*32, spriteDir*32, 32, 32));
    toRender.setOrigin(16, 16);
    toRender.setPosition(position);
    window.draw(toRender);
}

sf::Vector2i NPC::getIndexPosition() {
    int x = (int)floor(position.x);
    int y = (int)floor(position.y);
    return sf::Vector2i(x/32, y/32);
}

Movement NPC::getDirection()
{
    return direction;
}

void NPC::setPosition(sf::Vector2f add)
{
    position += add;
}

void NPC::setPositionFix(sf::Vector2f tis)
{
    position = tis;
}

void NPC::printDirection()
{
    std::cout << direction << std::endl;
}

