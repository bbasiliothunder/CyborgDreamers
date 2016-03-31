#include "StateManager.h"
#include "GameState.h"

GameState::GameState(StateManager* sm): State(sm), sm(sm){
}

}
void GameState::handleInput(int u, int v) {

}

void GameState::update(float dt) {

}

void GameState::draw(sf::RenderWindow& window) const {

}
