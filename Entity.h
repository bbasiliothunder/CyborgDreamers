#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include <SFML/Graphics.hpp>

enum Movement {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STAY
};

class Entity {
protected:
    sf::Vector2f position;
    Movement direction;
    sf::Texture spriteSheet;
public:
    virtual void update(float dt) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual sf::Vector2f getPosition() {
        return position;
    }
    virtual sf::Vector2i getIndexPosition() {
        return sf::Vector2i((int)position.x, (int)position.y);
    }
};

#endif // ENTITY_H_INCLUDED
