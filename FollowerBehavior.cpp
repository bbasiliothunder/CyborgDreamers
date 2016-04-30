#include "FollowerBehavior.h"
#include "NPC.h"
#include "EntitySubclass.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdio>


FollowerBehavior FollowerBehavior::getInstance() {
    static FollowerBehavior move;
    return move;
}

void FollowerBehavior::operator() (NPC* npc, float dt, Map map, sf::Vector2f next, Movement newDir, Character *chars) {
    time+=dt;
    sf::Vector2i inter = chars->getIndexPosition();
    float newX = (float)inter.x * 32;
    float newY = (float)inter.y * 32;
    sf::Vector2f thischar(newX, newY);
    if(nextcor != thischar)
    {
        npc->setPositionFix(nextcor);
        npc->setDirection(nextDir);
        nextcor = next;
        nextDir = newDir;
    }
}
