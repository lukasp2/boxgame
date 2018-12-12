#pragma once
#include "Game.h"
#include "Entity.h"

class Wall : public Entity
{
public:
	Wall(Game& game, sf::RectangleShape b, sf::Vector2f size, sf::Vector2f position);

	bool update(float deltaTime) override	{ return 0; }
	void draw()					 override	{ game.window.draw(body); }

private:
	sf::RectangleShape body;
};