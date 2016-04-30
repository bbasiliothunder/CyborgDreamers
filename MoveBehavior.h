#ifndef MOVEBEHAVIOR_H_INCLUDED
#define MOVEBEHAVIOR_H_INCLUDED
#include "Entity.h"
#include <SFML/Window.hpp>

class Character;
class NPC;
class Map;
class MoveBehavior{
    virtual void operator() (NPC *npc, float dt, Map map) = 0;
    virtual void operator() (NPC *npc, float dt, Map map, sf::Vector2f next, Movement newDir, Character *chars) = 0;
};



#endif
