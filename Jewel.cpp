#include "Jewel.h"
#include 

Jewel::Jewel()
{
	rect.setSize(sf::Vector2f(44,32));
	rect.setPosition(400, 200);
	rect.setFillColor(sf::Color::Blue);
	sprite.setTextureRect(sf::IntRect(0, 0, 44, 32));
}

void Jewel::update()
{
	sprite.setPosition(rect.getPosition());
}