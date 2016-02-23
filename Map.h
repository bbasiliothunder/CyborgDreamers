#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
#include <SFML/Graphics.hpp>
class Map {
private:
    sf::Texture tileTexture;
    sf::Vector2i map[100][100];
    sf::Vector2i limit;
public:
    Map(std::string s);
    void draw(sf::RenderWindow& window) const;
};

#endif // MAP_H_INCLUDED
