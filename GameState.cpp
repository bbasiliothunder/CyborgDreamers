#include "StateSubclass.h"
#include "StateManager.h"

GameState::GameState(StateManager* sm): sm(sm), map(Map("1")) {

}

void GameState::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        player.setDirection(Movement::UP);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        player.setDirection(Movement::DOWN);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        player.setDirection(Movement::LEFT);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        player.setDirection(Movement::RIGHT);
}

void GameState::update(float dt) {
    player.update(dt);
}

void GameState::draw(sf::RenderWindow& window) const {
    map.draw(window);
    player.draw(window);
}
