#include "StateManager.h"

void StateManager::addState(State* state) {
    states.push_back(state);
}

void StateManager::push(unsigned int id, std::string pass) {
    if(!state_stack.empty())
        state_stack.back()->onDeactivate();

    state_stack.push_back(states[id]);
    state_stack.back()->onActivate(pass);
}

void StateManager::pop(unsigned int lvl, std::string pass) {
    if(state_stack.empty()) return;
    state_stack.back()->onDeactivate();

    unsigned int count = lvl-1;
    while(!state_stack.empty() && count-->0) {
        state_stack.back()->onDeactivate();
        state_stack.pop_back();
    }

    if(!state_stack.empty()) {
        state_stack.back()->onActivate(pass);
    }
}

<<<<<<< HEAD
void StateManager::handleInput(int u, int v) {
    if(state_stack.empty()) return;
    state_stack.back()->handleInput(u, v);
=======
void StateManager::handleInput() {
    if(state_stack.empty()) return;
    state_stack.back()->handleInput();
>>>>>>> d2e179a5989c6296ddfd72f0f2f115c64215c0ac
}

void StateManager::update(float dt) {
    if(state_stack.empty()) return;
    state_stack.back()->update(dt);
}

void StateManager::draw(sf::RenderWindow& window) const {
    if(state_stack.empty()) return;
    state_stack.back()->draw(window);
}
