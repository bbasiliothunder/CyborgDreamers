#include "KidBehavior.h"
#include "NPC.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdio>

KidBehavior KidBehavior::getInstance() {
    static KidBehavior move;
    return move;
}

void KidBehavior::operator() (NPC* npc, float dt, Map map) {
    time+=dt;
    sf::Vector2i next;
    sf::Vector2i tile;
    if(fmod(time, 3.f) == 0);
    {
        std::cout << time << std::endl;
        switch(npc->getDirection())
        {
        case UP:
            {
                next = npc->getIndexPosition() + sf::Vector2i(0, -1);
                tile = map.getTile(next);
                if(!(tile.x == 1 && tile.y == 1))
                {
                    npc->setDirection(Movement::RIGHT);
                    npc->setPosition(speedRight);
                }
                else
                {
                    npc->setDirection(npc->getDirection());
                    npc->setPosition(speedUp);
                }
                break;
            }
        case DOWN:
            {
                next = npc->getIndexPosition() + sf::Vector2i(0, 1);
                tile = map.getTile(next);
                if(!(tile.x == 1 && tile.y == 1))
                {
                    npc->setDirection(Movement::LEFT);
                    npc->setPosition(speedLeft);
                }
                else
                {
                    npc->setDirection(npc->getDirection());
                    npc->setPosition(speedDown);
                }
                break;
            }
        case LEFT:
            {
                next = npc->getIndexPosition() + sf::Vector2i(-1, 0);
                tile = map.getTile(next);
                if(!(tile.x == 1 && tile.y == 1))
                {
                    npc->setDirection(Movement::UP);
                    npc->setPosition(speedUp);
                }
                else
                {
                    npc->setDirection(npc->getDirection());
                    npc->setPosition(speedLeft);
                }
                break;
            }
        case RIGHT:
            {
                next = npc->getIndexPosition() + sf::Vector2i(1, 0);
                tile = map.getTile(next);
                if(!(tile.x == 1 && tile.y == 1))
                {
                    npc->setDirection(Movement::DOWN);
                    npc->setPosition(speedDown);
                }
                else
                {
                    npc->setDirection(npc->getDirection());
                    npc->setPosition(speedRight);
                }
                break;
            }
            npc->printDirection();
        }
    }
}
