#ifndef GOAROUNDBEHAVIOR_HPP_INCLUDED
#define GOAROUNDBEHAVIOR_HPP_INCLUDED
#include "MoveBehavior.h"
#include "Map.h"
#include <SFML/Window.hpp>

class NPC;
class GoAroundBehavior: public MoveBehavior
{
private:
    sf::Vector2f speedUp, speedDown, speedLeft, speedRight;
    float timex;
public:
    GoAroundBehavior(): speedUp(0, -20), speedDown(0,20), speedRight(20,0), speedLeft(-20, 0) {}
    static GoAroundBehavior getInstance();
    void operator() (NPC* npc, float dt, Map map);
    void operator() (NPC *npc, float dt, Map map, sf::Vector2f next, Movement newDir, Character *chars) {}
};

#endif // GOAROUNDBEHAVIOR_HPP_INCLUDED
