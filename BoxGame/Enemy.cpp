#include "Enemy.h"
#include "Hero.h"
#include "Disappearing_Character.h"

Enemy::Enemy(Game& game, sf::Color color, float size, int speed, int health, size_t damage, std::string name)
	: Character{ game, size, speed, health, name, color }
{
	Character::name.setFillColor(color);
	Character::name.setCharacterSize(15);

	healthBar.setFillColor	(sf::Color::Red);
	healthBar.setSize		(sf::Vector2f{ 45, 4 });
	bar.setSize				(sf::Vector2f{ 45, 4 });
	bar.setFillColor		(sf::Color::Black);
	bar.setOutlineThickness	(1);
}

bool Enemy::update(float deltaTime)
{
	seekPosition = game.player->getPosition();

	if (game.player->changed_movement)
	{
		game.player->changed_movement = false;
		startPosition = body.getPosition();
		x = 0;
	}
	Character::move();

	//update_more()?

	name.setPosition(body.getPosition().x - body.getRadius() - 10, body.getPosition().y - body.getRadius() - 40);
	bar.setPosition(body.getPosition().x - body.getRadius() - 3, body.getPosition().y - body.getRadius() - 12);
	healthBar.setPosition(body.getPosition().x - body.getRadius() - 3, body.getPosition().y - body.getRadius() - 12);

	if (health <= 0)
		game.entities.push_back( std::make_shared<Disappearing_Character>(game, body, body.getOutlineColor(), 40));
	
	return health <= 0;
}

void Enemy::draw_more()
{
	game.window.draw(bar);
	game.window.draw(healthBar);
}

void Enemy::got_damaged(size_t damage)
{
	health -= damage;
	healthBar.setScale(float(health) / float(100.0), 1);
}
