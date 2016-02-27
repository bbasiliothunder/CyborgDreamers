#ifndef STATESUBCLASS_H_INCLUDED
#define STATESUBCLASS_H_INCLUDED
#include "State.h"
#include "EntitySubclass.h"
#include "Map.h"
#include "Button.h"
#include <vector>
#include "SFML/Graphics.hpp"
#include <vector>

class GameState: public State {
private:
    Map map;
    StateManager* sm;
    bool isActive;
    Character player;
public:
    GameState(StateManager* sm);
    void handleInput(int u, int v);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

class MenuState: public State {
private:
    StateManager* sm;
    bool isActive;
    Button join;
    Button host;
    Button options;
    int cover;
    sf::RenderWindow window2;
public:
    MenuState(StateManager* sm);
    void handleInput(int u, int v);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

class Splash: public State
{
private:
    StateManager* sm;
    bool isFadingIn;
    bool isOnPause;
    bool isFadingOut;
    float timeCount;
    int logoAlpha;
public:
    Splash(StateManager* sm);
    void update(float dt);
    void draw(sf::RenderWindow&) const;
    void onActivate(std::string accept);
    void onDeactivate();
    void handleInput(int u, int v);
};

#endif // STATESUBCLASS_H_INCLUDED
