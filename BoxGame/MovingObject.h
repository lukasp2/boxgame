#pragma once
#include <SFML/Graphics.hpp>
#include "Collider.h"
#include "Resources.h"
#include <math.h>

class MovingObject
{
public:
	~MovingObject() = default;
	MovingObject(sf::RectangleShape rs, sf::Vector2f velocity, float angle, sf::Vector2f position);

	void update(float deltaTime);
	void OnCollision();

	void Draw(sf::RenderWindow& window) { window.draw(body); }
	void setPosition(sf::Vector2f pos) { body.setPosition(pos); }
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f& getColDirection() { return colDirection; }
	Collider GetCollider() { return Collider(body); }

protected:
	sf::RectangleShape body;
	sf::Vector2f colDirection;
	sf::Vector2f velocity;

private:
	float angle;
};


