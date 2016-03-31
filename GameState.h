#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

class GameState: public State {
private:
    StateManager* sm;
    sf::Thread* clientThread;
    sf::Thread* serverThread;
    bool isActive;
    bool isHost;
public:
    GameState(StateManager* sm);
    void serverLoop();
    void clientLoop();
    void onActivate(std::string accept);
    void onDeactivate();
    void handleInput(int u, int v);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

#endif // GAMESTATE_H_INCLUDED
