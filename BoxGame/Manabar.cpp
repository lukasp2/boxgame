#include "Manabar.h"
#include "Hero.h"
#include <sstream>
#include <iomanip>

Manabar::Manabar(Game & game, sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: Bar{ game, position, size, color }
{
	manatext.setFont(game.courier_font);
	manatext.setCharacterSize(13);
	manatext.setOutlineThickness(1);
	manatext.setOutlineColor(sf::Color(90, 90, 90, 100));
	manatext.setFillColor(sf::Color::White);
	manatext.setPosition(sf::Vector2f(-45, 400));
}

bool Manabar::update()
{
	float mana = float(game.player->getMana());
	bar.setScale(float(game.player->getMana()) / float(100.0), 1);

	if (mana < 100)
	{
		std::stringstream ss;
		ss << std::setprecision(1) << std::fixed << game.player->get_mana_reg();

		manatext.setString(std::to_string(static_cast<int>(mana)) + " / 100 " + " ( +" + ss.str() + "/sec )");
	}
	else
	{
		manatext.setString(std::to_string(static_cast<int>(mana)) + " / 100");
	}


	return false;
}

void Manabar::draw()
{
	game.window.draw(bar);
	game.window.draw(edge);
	game.window.draw(manatext);
}