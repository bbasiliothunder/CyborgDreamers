#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Universal.h"
#include <stdlib.h>
#include <iostream>

Button::Button()
{
    font.loadFromFile("assets/fonts/black_jack.ttf");
}

float clamp(float var, float mini, float maxi)
{
    if(var < mini) return mini;
    else if( var > maxi) return maxi;
    return var;
}

bool Button::checkCollision(float u, float v)
{
    float targetX = clamp(u, center.x-half_diagonal.x, center.x+half_diagonal.x);
    float targetY = clamp(v, center.x-half_diagonal.y, center.y+half_diagonal.y);
    hover = (targetX==u && targetY==v);
    return hover;
}

void Button::draw(sf::RenderWindow& window) const
{
    float drawPosX = center.x-half_diagonal.x;
    float drawPosY = center.y-half_diagonal.y;
    float width = half_diagonal.x*2;
    float height = half_diagonal.y*2;
    unsigned int fontSize = (unsigned int)(height*0.75);
    sf::RectangleShape drop;
    drop.setSize(sf::Vector2f(width, height));
    sf::Text label(content, font, fontSize);

    if(hover)
    {
        label.setColor(sf::Color::Black);
        drop.setFillColor(sf::Color::White);
    }
    else
    {
        label.setColor(sf::Color::White);
        drop.setFillColor(sf::Color(0,0,0,0));
    }
    drop.setPosition(drawPosX, drawPosY);
    label.setPosition(drawPosX+3, drawPosY+3);
    window.draw(drop);
    window.draw(label);
}

void Button::setPosition(float u, float v)
{
    center = sf::Vector2f(u, v);
}

void Button::setDimension(float u, float v)
{
    half_diagonal = sf::Vector2f(u/2.0, v/2.0);
}

void Button::setContent(const std::string cont)
{
    content = cont;
}
