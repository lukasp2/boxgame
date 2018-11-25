#include "Warrior.h"
#include "Hero.h"

Warrior::Warrior(sf::RenderWindow& window) :
	// color, size, speed, health, damage, name
	Enemy{ window, sf::Color::Red, 20.0f, 100, 150, 10, "Saruman" }
{

}