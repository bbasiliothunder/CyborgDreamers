#ifndef ENTITYSUBCLASS_H_INCLUDED
#define ENTITYSUBCLASS_H_INCLUDED
#include "Entity.h"

class Character: public Entity {
protected:
    sf::Vector2f position;
    Movement direction;
    sf::Texture spriteSheet;
    int lastTic;

    int spriteDir;
    int spriteAction;
public:
    Character();
    void update(float dt);
    void draw(sf::RenderWindow& window) const;
    void setDirection(Movement m);
    void setFace(Movement m);
    sf::Vector2i getIndexPosition();
};

#endif // ENTITYSUBCLASS_H_INCLUDED
