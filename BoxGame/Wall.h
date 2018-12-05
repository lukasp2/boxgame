#pragma once
#include "Entity.h"
#include "Collider.h"

class Wall : public Entity
{
public:
	Wall(Game& game, sf::RectangleShape body, sf::Vector2f size, sf::Vector2f position);

	bool update(float deltaTime) override	{ return 0; } //{ body.move(velocity * deltaTime); return 0; }
	void draw()					 override	{ window.draw(body); }

	Collider getCollider() { return Collider(body);}

private:
	sf::RectangleShape	body;
};