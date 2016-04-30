#ifndef STATESUBCLASS_H_INCLUDED
#define STATESUBCLASS_H_INCLUDED
#include "State.h"
#include "EntitySubclass.h"
#include "NPC.h"
#include "Map.h"
#include "Button.h"
#include "Universal.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <vector>
#include <SFML/Network.hpp>

class GameState: public State {
private:
    Map map;
    StateManager* sm;
    bool isActive;
    Character player;
    NPC kid;
    NPC follower;
    NPC tourist;
    NPC statue;
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

class JoinState :public State
{
private:
    StateManager *sm;
    bool isActive;
    sf::Font font;
    sf::UdpSocket socket;
    unsigned short port;
    std::string ip;
    sf::IpAddress ipaddress;
    unsigned int fontSize = 20;
    Button back;
    sf::RenderWindow rw;
    int cover;
public:
    JoinState(StateManager* sm);
    void handleInput(int u, int v);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

#endif // STATESUBCLASS_H_INCLUDED
