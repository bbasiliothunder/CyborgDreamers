#include "StateSubclass.h"
#include "StateManager.h"

GameState::GameState(StateManager* sm): sm(sm), map(Map("1")) {

}

void GameState::handleInput() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sf::Vector2i nextPos = player.getIndexPosition()+sf::Vector2i(0, -1);
        sf::Vector2i tile = map.getTile(nextPos);
        if(tile.x==1 && tile.y==1)
            player.setDirection(Movement::UP);
        else
            player.setFace(Movement::UP);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sf::Vector2i nextPos = player.getIndexPosition()+sf::Vector2i(0, 1);
        sf::Vector2i tile = map.getTile(nextPos);
        if(tile.x==1 && tile.y==1)
            player.setDirection(Movement::DOWN);
        else
            player.setFace(Movement::DOWN);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        sf::Vector2i nextPos = player.getIndexPosition()+sf::Vector2i(-1, 0);
        sf::Vector2i tile = map.getTile(nextPos);
        if(tile.x==1 && tile.y==1)
            player.setDirection(Movement::LEFT);
        else
            player.setFace(Movement::LEFT);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        sf::Vector2i nextPos = player.getIndexPosition()+sf::Vector2i(1, 0);
        sf::Vector2i tile = map.getTile(nextPos);
        if(tile.x==1 && tile.y==1)
            player.setDirection(Movement::RIGHT);
        else
            player.setFace(Movement::RIGHT);
    }
}

void GameState::update(float dt) {
    player.update(dt);
}

void GameState::draw(sf::RenderWindow& window) const {
    map.draw(window);
    player.draw(window);
}
