#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Game.h"

class Entity
{
public:
	~Entity() = default;
	
	//Entity contains a reference the state that its in
	Entity(Game& game) : game{ game }, window{ game.window } {}

	virtual void draw() = 0;
	virtual void update(float deltaTime) = 0;

protected:
	Game& game;
	sf::RenderWindow& window;
};

