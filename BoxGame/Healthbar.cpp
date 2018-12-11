#include "Healthbar.h"
#include "Hero.h"
#include <sstream>

Healthbar::Healthbar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color) 
	: Bar {game, position, size, color}
{
	sf::Text healthtext;
	healthtext.setFont(game.courier_font);
	healthtext.setCharacterSize(16);
	healthtext.setFillColor(sf::Color::Black);
	healthtext.setPosition(sf::Vector2f(-50, 380));
	healthtext.setString("100 / 100");
}

bool Healthbar::update()
{
	bar.setScale(game.player->getHealth() / float(100.0), 1);

	std::stringstream ss{ game.player->getHealth() };
	healthtext.setString(ss.str() + " / 100");

	return false;
}

void Healthbar::draw()
{
	game.window.draw(healthtext);
	game.window.draw(bar);
}