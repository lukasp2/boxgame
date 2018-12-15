#include "Mini_Healthbar.h"
#include "Hero.h"
#include <iostream>

Mini_Healthbar::Mini_Healthbar(Game& game, Character& character, sf::Vector2f size, sf::Color color)
	: Bar{ game, character.getPosition(), size, color }, character{ character }
{
	edge.setOutlineColor(sf::Color(100,100,100));
}

bool Mini_Healthbar::update()
{
	bar.setPosition(character.getPosition().x - 20, character.getPosition().y - 38);
	edge.setPosition(character.getPosition().x - 20, character.getPosition().y - 38);
	
	bar.setScale(float(character.getHealth()) / float(character.getMaxHealth()), 1);

	return character.getHealth() <= 0;
}

void Mini_Healthbar::draw()
{
	game.window.draw(bar);
	game.window.draw(edge);
}
