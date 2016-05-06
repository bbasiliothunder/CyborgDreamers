#include "Jewel.h"

//Graphical text display for jewels stolen
sf::Font font;
if (!font.loadFromFile(resourcePath() + "assets/fonts/black_jack.ttf"))
{
	return EXIT_FAILURE;
}
sf::Text text("Jewels: ", font, 25);
text.setColor(sf::Color::Black);
text.setCharacterSize(20);
text.setPosition(0,0);

/**
sf::Texture textureFloor
if(!textureFloor.loadFromFile(resourcePath() + "assets/sprites/jewel.png"))
{
	return EXIT_FAILURE;
}
**/

sf::Texture textureJewel;
if (!textureJewel.loadFromFile(resourcePath() + "assets/sprites/jewel.jpg"))
{
	return EXIT_FAILURE;
}

/**
//Floor Vector Array
vector<floor>::const_iterator iter20;
vector<floor> floorArray;

class floor floor1;
floor1.sprite.setTexture(textureFloor);
floor1.sprite.setTextureRect(sf::IntRect(0,0,64,64)
**/

//Jewel Vector Array
vector<jewel>::const_iterator iter7;
vector<jewel> jewelArray;

/**
//Lay floor tiles
counter = 0;
while (counter <=)
floor1.rect.setPosition(0, 0);
floor.push_back(floor1);
**/

//Display Jewel
class jewel jewel1;
jewel1.sprite.setTexture(textureJewel);
jewel1.rect.setPosition(500, 500);
jewel.push_back(jewel1);

/**
//Draw Floor
counter = 0;
for (iter20 = floorArray.begin(); iter20 != floorArray.end(); iter20++)
{
	window.draw(floorArray[counter].sprite);

	counter++;
}
**/

//Draw Jewels
counter = 0;
for (iter7 = jewelArray.begin(); iter7 != jewel.end(); iter7++)
{
	jewel[counter].update();
	window.draw(jewel[counter].rect);
	window.draw(jewel[counter].sprite);

	counter++;
}

//Player collides with Jewel
counter = 0;
for (iter7 = jewelArray.begin(); iter7 != jewel.end(); iter7++)
{
	if(Character1.rect.getGlobalBounds().intersects(jewelArray[counter].rect.getGlobalBounds()))
	{
		if(jewelArray[counter].isJewel == true)
		{
			Character1.jewels += jewelArray[counter];
		}

		jewelArray[counter].destroy = true;
	}

	counter++;
}

//Delete Jewels when stolen
counter = 0;
for (iter7 = jewelArray.begin() iter7 !=jewel.end(); iter7++)
{
	if (jewelArray[counter].destroy == true)
	{
		jewelArray.erase(iter7);
		break;
	}

	counter++;
}

//Jewels text
text.setString("Jewels: " + to_string(Character1.jewels));
window.draw(text);
