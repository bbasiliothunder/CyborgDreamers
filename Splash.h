#ifndef SPLASH_H_INCLUDED
#define SPLASH_H_INCLUDED

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

#endif // SPLASH_H_INCLUDED
