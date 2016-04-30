#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED
#include "Entity.h"
#include "KidBehavior.h"
#include "FollowerBehavior.h"
#include "LookAroundBehavior.hpp"
#include "GoAroundBehavior.hpp"
class NPC: public Entity{
protected:
    sf::Vector2f position;
    Movement direction;
    sf::Texture spriteSheet;
    int lastTic;
    KidBehavior kb;
    FollowerBehavior fl;
    LookAroundBehavior la;
    GoAroundBehavior ga;

    int spriteDir;
    int spriteAction;
    Map map;
public:
    NPC();
    void update(float dt, Map map, int ai);
    void update(float dt, Map map, sf::Vector2f chars, Movement charsm, Character *char2);
    void update(float dt, Map map){}
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
    void setDirection(Movement m);
    void setFace(Movement m);
    sf::Vector2i getIndexPosition();
    void setSpeed(float spd);
    Movement getDirection();
    void setPosition(sf::Vector2f add);
    void setPositionFix(sf::Vector2f tis);
    void printDirection();
};
#endif // NPC_H_INCLUDED
