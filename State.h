#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED
#include<SFML/Graphics.hpp>

class StateManager;
class State {
protected:
    friend class StateManager;
    StateManager* manager;
    bool isActive;
public:
    virtual void pass(std::string s){}
    virtual void onActivate() {}
    virtual void onDeactivate() {}

    virtual void handleInput() = 0;
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
};

#endif // STATE_H_INCLUDED
