#ifndef KIDBEHAVIOR_H_INCLUDED
#define KIDBEHAVIOR_H_INCLUDED
#include "MoveBehavior.h"
#include "Map.h"
#include <SFML/Window.hpp>

class NPC;
class KidBehavior: public MoveBehavior
{
private:
    sf::Vector2f speedUp, speedDown, speedLeft, speedRight;
    float time;
public:
    KidBehavior(): speedUp(0, -4), speedDown(0,4), speedRight(4,0), speedLeft(-4, 0) {}
    static KidBehavior getInstance();
    void operator() (NPC* npc, float dt, Map map);
    void operator() (NPC *npc, float dt, Map map, sf::Vector2f next, Movement newDir, Character *chars) {}
};

#endif // KIDBEHAVIOR_H_INCLUDED
