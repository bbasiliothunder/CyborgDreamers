#ifndef STATESUBCLASS_H_INCLUDED
#define STATESUBCLASS_H_INCLUDED
#include "State.h"
#include "EntitySubclass.h"
#include <vector>

class GameState: public State {
private:
    StateManager* sm;
    bool isActive;
    Character player;
public:
    GameState(StateManager* sm);
    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

#endif // STATESUBCLASS_H_INCLUDED
