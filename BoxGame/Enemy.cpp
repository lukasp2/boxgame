#include "Enemy.h"
#include "Hero.h"
#include "Projectile.h"
#include "Disappearing_Character.h"

Enemy::Enemy(Game& game, sf::Color color, float size, int speed, float health, size_t damage, std::string name)
	: Character{ game, size, speed, health, name, color }, max_health{ health }
{
	Character::name.setFillColor(color);
	Character::name.setCharacterSize(15);

	healthBar.setFillColor	(sf::Color::Red);
	healthBar.setSize		(sf::Vector2f{ 45, 4 });
	
	edge.setSize			(sf::Vector2f{ 45, 4 });
	edge.setFillColor		(sf::Color::Black);
	edge.setOutlineThickness(1);
	edge.setOutlineColor(sf::Color(100, 100, 100));

	body.setPosition(-200,-200);
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
	edge.setPosition(body.getPosition().x - body.getRadius() - 3, body.getPosition().y - body.getRadius() - 15);
	healthBar.setPosition(body.getPosition().x - body.getRadius() - 3, body.getPosition().y - body.getRadius() - 15);

	if (health <= 0)
		game.entities.push_back( std::make_shared<Disappearing_Character>(game, body, body.getOutlineColor(), 40));
	
	return health <= 0;
}

void Enemy::draw_more()
{
	game.window.draw(edge);
	game.window.draw(healthBar);
}

void Enemy::onCollision(Entity& otherEntity)
{

}

void Enemy::damage_enemy(size_t damage)
{
	health -= damage;
	healthBar.setScale(float(health) / max_health, 1);
}
