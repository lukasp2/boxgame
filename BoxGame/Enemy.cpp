#include "Enemy.h"
#include "Hero.h"

Enemy::Enemy(Game& game, sf::Color color, float size, int speed, int health, size_t damage, std::string name)
	: Character{ game, size, speed, health, name, color }
{
	Character::name.setFillColor(color);
	Character::name.setCharacterSize(15);

	healthBar.setFillColor(sf::Color::Red);
	healthBar.setSize(sf::Vector2f{ 45, 4 });
	bar.setSize(sf::Vector2f{ 45, 4 });
	bar.setFillColor(sf::Color::Black);
	bar.setOutlineThickness(1);
}

void Enemy::update(float deltaTime)
{
	seekPosition = game.player->getPosition();

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		startPosition = sf::Vector2f{ body.getPosition().x, body.getPosition().y };
		x = 0;
	}

	Character::move();

	//update_more(playerPos)?

	name.setPosition(body.getPosition().x - body.getRadius() - 10, body.getPosition().y - body.getRadius() - 40);
	bar.setPosition(body.getPosition().x - body.getRadius() - 3, body.getPosition().y - body.getRadius() - 12);
	healthBar.setPosition(body.getPosition().x - body.getRadius() - 3, body.getPosition().y - body.getRadius() - 12);
}

void Enemy::draw_more()
{
	window.draw(bar);
	window.draw(healthBar);
}

void Enemy::got_damaged(size_t damage)
{
	health -= damage;
	healthBar.setScale(health / float(100.0), 1);
}
