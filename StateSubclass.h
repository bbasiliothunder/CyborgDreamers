#ifndef STATESUBCLASS_H_INCLUDED
#define STATESUBCLASS_H_INCLUDED
#include "State.h"
#include "Button.h"

class GameState: public State {
private:
    StateManager* sm;
    bool isActive;
public:
    GameState(StateManager* sm);
    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow& window) const ;
};

class MenuScreen: public State {
private:
    StateManager* sm;
    bool isActive;
    sf::Texture logoTexture;
    int cover;
public:
    MenuScreen(StateManager* sm);
    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

class Splash: public State
{
private:
    StateManager* sm;
    bool isActive;
    bool isFadingIn;
    bool isOnPause;
    bool isFadingOut;
    float timeCount;
    int logoAlpha;
public:
    Splash(StateManager* sm);
    void handleInput();
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
    void onActivate();
    void onDeactivate();
    void onClick(float, float);
};

#endif // STATESUBCLASS_H_INCLUDED
