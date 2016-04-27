#include "StateManager.h"
#include "GameState.h"

GameState::GameState(StateManager* sm): State(sm), sm(sm){
}

void GameState::serverLoop() {
    while(isActive) {
        std::cout << "ge\n";
    }
    std::cout << "byebye\n";
}

void GameState::clientLoop() {
    while(isActive) {
        std::cout << "lang\n";
    }
    std::cout << "sayonara\n";
}

void GameState::onActivate(std::string activate) {
    isActive = true;
    isHost = false;
    if(activate=="host") {
        isHost = true;
        serverThread = new sf::Thread(&GameState::serverLoop, this);
        serverThread->launch();
    }
    clientThread = new sf::Thread(&GameState::clientLoop, this);
    clientThread->launch();
}

void GameState::onDeactivate() {
    isActive = false;
    clientThread->wait();
    delete clientThread;
    clientThread = nullptr;

    if(isHost) {
        serverThread->wait();
        delete serverThread;
        serverThread = nullptr;
    }
}

void GameState::handleInput(int u, int v, const std::string& typed) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        popSelf(1);
    }
}

void GameState::update(float dt) {

}

void GameState::draw(sf::RenderWindow& window) const {
}
