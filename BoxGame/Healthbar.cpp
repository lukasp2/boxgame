#include "Healthbar.h"
#include "Hero.h"
#include <sstream>
#include <iomanip>

Healthbar::Healthbar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color) 
	: Bar {game, position, size, color}
{
	healthtext.setFont(game.courier_font);
	healthtext.setCharacterSize(13);
	healthtext.setOutlineThickness(1);
	healthtext.setOutlineColor(sf::Color(90,90,90,100));
	healthtext.setFillColor(sf::Color::White);
	healthtext.setPosition(sf::Vector2f(-45, 382));
}

bool Healthbar::update()
{
	float health = static_cast<float>(game.player->getHealth());
	float max_health = static_cast<float>(game.player->getMaxHealth());

	if (health > 0)
	{
		bar.setScale( health / max_health, 1);
	}
	else
	{
		bar.setScale(0, 1);
	}
	
	if (health < 100)
	{
		std::stringstream ss;
		ss << std::setprecision(1) << std::fixed << game.player->get_health_reg();
		
		if (health < 0)
		{
			healthtext.setString("0 / " + std::to_string(static_cast<int>(max_health)) + " ( +" + ss.str() + "/sec )");
		}
		else
		{
			healthtext.setString(std::to_string(static_cast<int>(health)) + " / " + std::to_string(static_cast<int>(max_health)) + " ( +" + ss.str() + "/sec )");
		}
	}
	else
	{
		healthtext.setString(std::to_string(static_cast<int>(health)) + " / " + std::to_string(static_cast<int>(max_health)));
	}

	return false;
}

void Healthbar::draw()
{
	game.window.draw(bar);
	game.window.draw(edge);
	game.window.draw(healthtext);
}

