#include "Enemy_Name.h"

Enemy_Name::Enemy_Name(Game& game, Character& enemy)
	: Text{ game, enemy.getPosition(), 15, enemy.getName(), enemy.getBody().getFillColor() }, enemy{ enemy }
{
	text.setFillColor(sf::Color::Red);
}

bool Enemy_Name::update()
{
	text.setPosition(enemy.getPosition().x - enemy.getRadius() - 10, enemy.getPosition().y - enemy.getRadius() - 40);

	return enemy.getHealth() <= 0;
}

void Enemy_Name::draw()
{
	game.window.draw(text);
}
