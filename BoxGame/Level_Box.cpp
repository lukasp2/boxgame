#include "Level_Box.h"

Level_Box::Level_Box(Game& game, Character& character) : 
	GUI_Object{ game },
	character{ character },
	current_level{ 0 }, 
	level_box_color{ sf::Color(15, 15, 15) }
{
	level_box.setSize(sf::Vector2f(12, 12));
	level_box.setFillColor(level_box_color);
	level_box.setOutlineColor(sf::Color(90, 90, 90));
	level_box.setOutlineThickness(1.0f);

	level_text.setOutlineThickness(1);
	level_text.setOutlineColor(sf::Color(90, 90, 90, 100));
	level_text.setFont(game.courier_font);
	level_text.setCharacterSize(13);
	level_text.setFillColor(sf::Color::White);
}

bool Level_Box::update()
{
	level_box.setPosition(character.getPosition().x - 44, character.getPosition().y - 40);
	level_text.setPosition(character.getPosition().x - 42, character.getPosition().y - 43);

	if (character.getLevel() > current_level)
	{
		current_level = character.getLevel();
		level_text.setString(std::to_string(current_level));

		if (current_level > 9)
		{
			level_box.setSize(sf::Vector2f(18, 12));
			level_box.setPosition(level_box.getPosition().x - 6, level_box.getPosition().y);
		}
	}

	if (character.getUpgradesAvailable() > 0)
	{
		level_box.setFillColor(sf::Color(150,120,0));
	}
	else
	{
		level_box.setFillColor(level_box_color);
	}

	return character.getHealth() <= 0;
}

void Level_Box::draw()
{
	game.window.draw(level_box);
	game.window.draw(level_text);
}
