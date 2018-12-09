#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Game.h"

class Disappearing_Character : public Entity
{
public:
	Disappearing_Character(Game& game, sf::CircleShape body, sf::Color color, size_t lifetime = 30);

	void draw()	override { game.window.draw(body); }
	bool update(float deltaTime) override;

private:
	sf::Color color;
	sf::CircleShape body;

	size_t lifetime;
	size_t total_lifetime;
};

