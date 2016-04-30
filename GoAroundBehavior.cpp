#include "GoAroundBehavior.hpp"
#include "NPC.h"
#include "EntitySubclass.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>


GoAroundBehavior GoAroundBehavior::getInstance() {
    static GoAroundBehavior move;
    return move;
}

void GoAroundBehavior::operator() (NPC *npc, float dt, Map map)
{
    timex+= dt;
    if(timex > 8)
    {
        srand(time(NULL));
    int direct = rand() % 4 + 1;
    sf::Vector2i next;
    sf::Vector2i tile;
    Movement dp;
    switch(direct)
    {
        case 1:
            {
                dp = Movement::UP;
                break;
            }
        case 2:
            {
                dp = Movement::DOWN;
                break;
            }
        case 3:
            {
                dp = Movement::LEFT;
                break;
            }
        case 4:
            {
                dp = Movement::RIGHT;
                break;
            }
    }
    npc->setDirection(dp);
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
        }
        timex = 0;
    }

}
