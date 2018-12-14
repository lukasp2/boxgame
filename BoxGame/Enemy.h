#pragma once
#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Mini_Healthbar.h"
#include "Level_Box.h"
#include "Game.h"

class Enemy : public Character
{
public:
	Enemy(Game& game, sf::Color color, float size, float speed, float health, size_t damage, std::string name);

	virtual bool update(float deltaTime) override;
	virtual void update_more() {};
	virtual void draw_more() override;

	void onCollision(Entity& otherEntity) override;

	size_t melee_attack();

private:
	Mini_Healthbar hpBar;
	Level_Box lvlBox;

	size_t damage{};
	sf::Clock melee_cooldown_clock;
	int melee_cooldown;
};