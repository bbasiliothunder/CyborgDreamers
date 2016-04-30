#include "LookAroundBehavior.hpp"
#include "NPC.h"
#include "EntitySubclass.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <ctime>


LookAroundBehavior LookAroundBehavior::getInstance() {
    static LookAroundBehavior move;
    return move;
}

void LookAroundBehavior::operator() (NPC *npc, float dt, Map map)
{
    timex+= dt;
    srand(time(NULL));
    int direct = rand() % 4 + 1;
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

}
