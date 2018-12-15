#pragma once
#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Mini_Healthbar.h"
#include "Level_Box.h"
#include "Game.h"

class Enemy : public Character
{
public:
	Enemy(Game& game, sf::Vector2f& position, sf::Color color, int level, float size, float speed, float health, size_t damage, std::string name);

	virtual bool update(float deltaTime) override;
	virtual void update_more() {};
	virtual void draw_more() override;

	void onCollision(Entity& otherEntity) override;

	size_t melee_attack();

protected:
	virtual size_t scale_damage(int level, size_t base_damage) = 0;
	virtual float scale_health(int level, float base_health) = 0;

private:
	size_t damage{};
	sf::Clock melee_cooldown_clock;
	int melee_cooldown;
};