#pragma once
#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Game.h"

class Enemy : public Character
{
public:
	Enemy(Game& game, sf::Color color, float size, int speed, float health, size_t damage, std::string name);

	virtual bool update(float deltaTime) override;
	virtual void draw_more() override;
	void onCollision(Entity& otherEntity) override;

	size_t getDamage() { return damage; }

private:
	sf::RectangleShape healthBar;
	sf::RectangleShape edge;
	
	size_t damage{};
};