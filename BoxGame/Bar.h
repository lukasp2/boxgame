#pragma once
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Entity.h"

class Bar : public Entity
{
public:
	Bar(Game& game, sf::Vector2f position, sf::Vector2f size, sf::Color color);
	~Bar() = default;

	void draw() override;
	bool update(float deltaTime) override;

private:
	sf::RectangleShape bar;
	sf::RectangleShape edge;
};

