#pragma once
#include "MovingObject.h"
#include "Static_Projectile.h"
#include "Game.h"

class Projectile : public MovingObject
{
public:
	enum class type { friendly, hostile };
	
	//~Projectile() = default;
	Projectile(Game& game, 
		sf::Vector2f& velocity, 
		sf::Vector2f& origin, 
		sf::CircleShape& body, 
		size_t damage, 
		size_t range,
		enum type t);

	Projectile(Game& game,
		Static_Projectile& proj,
		sf::Vector2f& velocity,
		sf::Vector2f& origin,
		enum type t);

	bool update (float deltaTime);
	void draw()	override { game.window.draw(body); }
	void onCollision(Entity& otherEntity) override;

	size_t getDamage()	{ return damage; }

private:
	type t;
	size_t	damage;
	size_t	range;

	size_t	lifeTimer{};
	bool	hit{ false };
};