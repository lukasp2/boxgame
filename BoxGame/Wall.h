#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"

class Wall 
{
public:
	Wall(sf::RectangleShape body, sf::Vector2f size, sf::Vector2f position);
	~Wall() = default;

	void OnCollision();
	void update();

	void Draw(sf::RenderWindow& window) { window.draw(body); }
	Collider GetCollider()				{ return Collider(body); }
	sf::Vector2f& getColDirection()		{ return colDirection; }

private:
	sf::Vector2f colDirection;
	sf::Vector2f velocity;
	sf::RectangleShape body;
};