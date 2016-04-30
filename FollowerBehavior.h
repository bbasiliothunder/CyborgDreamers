#ifndef FOLLOWERBEHAVIOR_H_INCLUDED
#define FOLLOWERBEHAVIOR_H_INCLUDED
#include "MoveBehavior.h"
#include "Map.h"
#include <SFML/Window.hpp>

class NPC;
class FollowerBehavior: public MoveBehavior
{
private:
    sf::Vector2f nextcor;
    float time;
    Movement nextDir;
    bool delay = 1;

public:
    static FollowerBehavior getInstance();
    void operator() (NPC *npc, float dt, Map map) {}
    void operator() (NPC* npc, float dt, Map map, sf::Vector2f next, Movement newDir, Character *chars);
};

#endif // FOLLOWERBEHAVIOR_H_INCLUDED
