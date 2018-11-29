#pragma once
#include <SFML/Graphics.hpp>

#include "Character.h"
#include <iostream>

class Enemy : public Character
{
public:
	Enemy(sf::RenderWindow& window, sf::Color color, float size, int speed, int health, size_t damage, std::string name);

	virtual void update(float deltaTime, sf::Vector2f playerPos);
	virtual void draw_more() override;

	void got_damaged(size_t damage);

	sf::RectangleShape healthBar;
	sf::RectangleShape bar;

private:
	size_t damage{};
};