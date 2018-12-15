#include "Enemy.h"
#include "Hero.h"
#include "Projectile.h"

#include "GUI.h"
#include "Damage_Text.h"
#include "Disappearing_Character.h"

Enemy::Enemy(Game& game, sf::Vector2f& position, sf::Color color, int level, float size, float speed, float health, size_t damage, std::string name)
	: Character{ game, size, speed, health, level, name, color },
	damage{ damage },
	melee_cooldown_clock{ },
	melee_cooldown{ 1 }
{
	// use a function setPosition which also sets InnerBodyPos
	body.setPosition(position);
	setInnerBodyPos();
}

void Enemy::damage_char(int damage)
{
	health -= damage;
	game.user_interface->add(std::make_unique<Damage_Text>(game, std::to_string(damage), sf::Color::White, body.getPosition()));
}

bool Enemy::update(float deltaTime)
{
	seekPosition = game.player->getPosition();

	if (game.player->changed_movement)
	{
		startPosition = body.getPosition();
		x = 0;
	}

	Character::move();
	update_more();
	
	if (health <= 0)
	{
		game.player->on_kill();
		game.add( std::make_shared<Disappearing_Character>(game, body, body.getOutlineColor(), 40));
	}
	
	return health <= 0;
}

void Enemy::draw_more()
{
}

void Enemy::onCollision(Entity& otherEntity)
{

}

size_t Enemy::melee_attack()
{
	if (melee_cooldown <= melee_cooldown_clock.getElapsedTime().asSeconds())
	{
		melee_cooldown_clock.restart();
		return damage;
	}

	return 0;
}
