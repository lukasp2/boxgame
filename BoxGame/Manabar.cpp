#include "Manabar.h"
#include "Hero.h"

Manabar::Manabar(Game & game, sf::Vector2f position, sf::Vector2f size, sf::Color color)
	: Bar{ game, position, size, color }
{
	manatext.setFont(game.courier_font);
	manatext.setCharacterSize(13);
	manatext.setOutlineThickness(1);
	manatext.setOutlineColor(sf::Color(90, 90, 90, 100));
	manatext.setFillColor(sf::Color::White);
	manatext.setPosition(sf::Vector2f(-45, 20));
}

bool Manabar::update()
{
	bar.setScale(float(game.player->getMana()) / float(100.0), 1);
	return false;
}

void Manabar::draw()
{
	game.window.draw(bar);
	game.window.draw(manatext);
}