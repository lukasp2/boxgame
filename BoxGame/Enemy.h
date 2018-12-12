#pragma once
#include <SFML/Graphics.hpp>

#include "Character.h"
#include "Game.h"

class Enemy : public Character
{
public:
	Enemy(Game& game, sf::Color color, float size, int speed, int health, size_t damage, std::string name);

	virtual bool update(float deltaTime) override;
	virtual void draw_more() override;

	void got_damaged(size_t damage);

private:
	sf::RectangleShape healthBar;
	sf::RectangleShape edge;

	size_t damage{};
};