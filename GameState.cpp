#include "StateSubclass.h"
#include "StateManager.h"

GameState::GameState(StateManager* sm): sm(sm) {

}

void GameState::handleInput() {

}

void GameState::update(float dt) {

}

void GameState::draw(sf::RenderWindow& window) const {
    sf::CircleShape ge(20);
    ge.setFillColor(sf::Color::Blue);
    ge.setPosition(100, 100);
    window.draw(ge);
}
