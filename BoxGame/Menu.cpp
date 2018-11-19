#include "Menu.h"
#include <iostream>

void Menu::moveUp() 
{
	if (selection - 1 >= 0)
	{
		textVector[selection].setFillColor(sf::Color::Green);
		selection--;
		textVector[selection].setFillColor(sf::Color::White);
	}
}

void Menu::moveDown()
{
	if (selection + 1 < static_cast<int>(textVector.size()))
	{
		textVector[selection].setFillColor(sf::Color::Green);
		selection++;
		textVector[selection].setFillColor(sf::Color::White);
	}
}

