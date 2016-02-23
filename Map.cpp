#include "Map.h"
#include <fstream>
#include <cctype>

Map::Map(std::string s) {
    tileTexture.loadFromFile("assets/sprites/tiles.png");
    std::ifstream reader("assets/maps/" + s + ".map");
    sf::Vector2i readCounter(0, 0);
    if(reader.is_open()) {
        std::string tileLocation;
        reader >> tileLocation;
        tileTexture.loadFromFile(tileLocation);
        while(!reader.eof())
        {
            std::string str;
            reader >> str;
            char x = str[0];
            char y = str[2];
            if(!std::isdigit(x) || !std::isdigit(y))
            {
                map[readCounter.x][readCounter.y] = sf::Vector2i(-1,-1);
            }
            else
            {
                //-'0' to convert the char x to an integer
                map[readCounter.x][readCounter.y] = sf::Vector2i(x - '0', y - '0');
            }
            if(reader.peek() == '\n')
            {
                readCounter.x = 0;
                readCounter.y++;
            }
            else
            {
                readCounter.x++;
            }
        }
        readCounter.y++;
    }
    limit = readCounter;
}

void Map::draw(sf::RenderWindow& window) const {
    sf::Sprite tiles;
    tiles.setTexture(tileTexture);
    for(int i = 0; i < limit.x; i++)
    {
        for(int j = 0; j < limit.y; j++)
        {
            if(map[i][j].x != -1 && map[i][j].y != -1)
            {
                tiles.setPosition(i * 32, j * 32);
                tiles.setTextureRect(sf::IntRect(map[i][j].x * 32,  map[i][j].y * 32 , 32 ,32));
                window.draw(tiles);
            }
        }
    }
}

sf::Vector2i Map::getTile(sf::Vector2i pos) {
    return map[pos.x][pos.y];
}
