#include "Enemy.h"
#include "Hero.h"
#include "Projectile.h"
#include "Disappearing_Character.h"

Enemy::Enemy(Game& game, sf::Vector2f& position, sf::Color color, int level, float size, float speed, float health, size_t damage, std::string name)
	: Character{ game, size, speed, health, level, name, color },
	hpBar{game, *this, sf::Vector2f(45,4), sf::Color::Red},
	lvlBox{game, *this},
	damage{ damage }, 
	melee_cooldown_clock{ },
	melee_cooldown{ 1 }
{
	Character::name.setFillColor(color);
	Character::name.setCharacterSize(15);

	body.setPosition(position);
	setInnerBodyPos();
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

	lvlBox.update();
	hpBar.update();

	name.setPosition(body.getPosition().x - body.getRadius() - 10, body.getPosition().y - body.getRadius() - 40);

	if (health <= 0)
	{
		game.player->on_kill();
		game.add( std::make_shared<Disappearing_Character>(game, body, body.getOutlineColor(), 40));
	}
	
	return health <= 0;
}

void Enemy::draw_more()
{
	lvlBox.draw();
	hpBar.draw();
	game.window.draw(name);
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
