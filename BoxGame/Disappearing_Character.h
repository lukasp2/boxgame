#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Game.h"

class Disappearing_Character : public Entity
{
public:
	Disappearing_Character(Game& game, sf::CircleShape body, sf::Color color, size_t lifetime = 30);

	void draw()	override;
	bool update(float deltaTime) override;

private:
	sf::Color color;
	sf::Color inner_color;

	sf::CircleShape body;
	sf::CircleShape inner_body;

	size_t lifetime;
	size_t total_lifetime;
};

