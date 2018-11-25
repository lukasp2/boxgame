#include "Hero.h"
#include <cmath>

#define PI 3.14159265

Hero::Hero(sf::RenderWindow& window, sf::Color color, float size, int speed, std::string name) 
	: Character{ window, size, speed, 100, name, color }
{}

void Hero::update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		float mouse_posx = sf::Mouse::getPosition(window).x - static_cast<float>(window.getSize().x / 2);
		float mouse_posy = sf::Mouse::getPosition(window).y - static_cast<float>(window.getSize().y / 2);

		seekPosition = sf::Vector2f{ mouse_posx, mouse_posy };
		startPosition = sf::Vector2f{ body.getPosition().x, body.getPosition().y };
	}
	
	Character::calculateOptimalMovement();
	
	body.move(velocity * deltaTime);
}
