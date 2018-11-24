#pragma once
#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(sf::RenderWindow& window, sf::Color color, float size, int speed, int health, size_t damage, std::string name);

	virtual void	update(float deltaTime, sf::Vector2f playerPos) = 0;
	virtual void	draw() = 0;

private:
	size_t damage{};
};