#include "Healthbar.h"
#include "Hero.h"
#include <sstream>

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
	bar.setScale(float(game.player->getHealth()) / float(100.0), 1);

	healthtext.setString(std::to_string(static_cast<int>(game.player->getHealth())) + " / 100");

	return false;
}

void Healthbar::draw()
{
	game.window.draw(bar);
	game.window.draw(healthtext);
}