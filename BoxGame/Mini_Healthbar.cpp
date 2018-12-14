#include "Mini_Healthbar.h"
#include "Hero.h"
#include <iostream>

Mini_Healthbar::Mini_Healthbar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: Bar{ game, position, size, color }, current_level{ game.player->getLevel() }
{
	edge.setOutlineColor(sf::Color(100,100,100));

	level_text.setFont(game.courier_font);
	level_text.setCharacterSize(13);
	level_text.setOutlineThickness(1);
	level_text.setOutlineColor(sf::Color(90, 90, 90, 100));
	level_text.setFillColor(sf::Color::White);

	level_box.setSize(sf::Vector2f(12, 12));
	level_box.setFillColor(sf::Color(15, 15, 15));
	level_box.setOutlineColor(sf::Color(90, 90, 90));
	level_box.setOutlineThickness(1.0f);

	// texts
	level_text.setFont(game.courier_font);
	level_text.setCharacterSize(13);
	level_text.setFillColor(sf::Color::White);
	level_text.setString("1");
}

bool Mini_Healthbar::update()
{
	bar.setPosition(game.player->getPosition().x - 20, game.player->getPosition().y - 38);
	edge.setPosition(game.player->getPosition().x - 20, game.player->getPosition().y - 38);
	level_box.setPosition(game.player->getPosition().x - 44, game.player->getPosition().y - 40);
	level_text.setPosition(game.player->getPosition().x - 42, game.player->getPosition().y - 43);
	
	if (game.player->getLevel() > current_level)
	{
		current_level = game.player->getLevel();
		level_text.setString(std::to_string(current_level));

		if (current_level == 10)
		{
			level_box.setSize(sf::Vector2f(18, 12));
			level_box.setPosition(level_box.getPosition().x - 6, level_box.getPosition().y);
		}
	}
	
	bar.setScale(float(game.player->getHealth()) / float(game.player->getMaxHealth()), 1);

	return false;
}

void Mini_Healthbar::draw()
{
	game.window.draw(bar);
	game.window.draw(edge);
	game.window.draw(level_box);
	game.window.draw(level_text);
}
