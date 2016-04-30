#ifndef LOOKAROUNDBEHAVIOR_HPP_INCLUDED
#define LOOKAROUNDBEHAVIOR_HPP_INCLUDED

#include "MoveBehavior.h"
#include "Map.h"
#include <SFML/Window.hpp>

class NPC;
class LookAroundBehavior: public MoveBehavior
{
private:
    float timex;
public:
    static LookAroundBehavior getInstance();
    void operator() (NPC* npc, float dt, Map map);
    void operator() (NPC *npc, float dt, Map map, sf::Vector2f next, Movement newDir, Character *chars) {}
};


#endif // LOOKAROUNDBEHAVIOR_HPP_INCLUDED
