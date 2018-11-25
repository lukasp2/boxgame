#pragma once
#include <SFML/Graphics.hpp>

#include "Character.h"

class Enemy : public Character
{
public:
	Enemy(sf::RenderWindow& window, sf::Color color, float size, int speed, int health, size_t damage, std::string name);

	void	update(float deltaTime, sf::Vector2f playerPos);
	
private:
	size_t damage{};
};