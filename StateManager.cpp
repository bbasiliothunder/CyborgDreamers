#include "StateManager.h"

void StateManager::addState(State* state) {
    states.push_back(state);
}

void StateManager::push(unsigned int id, const std::string& pass) {
    if(!state_stack.empty())
    {
       state_stack.back()->onDeactivate();
    }

    state_stack.push_back(states[id]);
    state_stack.back()->onActivate(pass);
}

void StateManager::pop(unsigned int lvl, const std::string& pass) {
    if(state_stack.empty()) return;
    state_stack.back()->onDeactivate();
    state_stack.pop_back();

    unsigned int count = lvl-1;
    while(!state_stack.empty() && count-->0) {
        state_stack.back()->onDeactivate();
        state_stack.pop_back();
    }

    if(!state_stack.empty()) {
        state_stack.back()->onActivate(pass);
    }
}

void StateManager::handleInput(int u, int v, const std::string& typed) {
    if(state_stack.empty()) return;
    state_stack.back()->handleInput(u, v, typed);
}

void StateManager::update(float dt) {
    if(state_stack.empty()) return;
    state_stack.back()->update(dt);
}

void StateManager::draw(sf::RenderWindow& window) const {
    if(state_stack.empty()) return;
    state_stack.back()->draw(window);
}
