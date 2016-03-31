#ifndef GAMESTATE_H_INCLUDED
#define GAMESTATE_H_INCLUDED

class GameState: public State {
private:
    StateManager* sm;
public:
    GameState(StateManager* sm);
    void handleInput(int u, int v);
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
};

#endif // GAMESTATE_H_INCLUDED
