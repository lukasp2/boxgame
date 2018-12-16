#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Game.h"

class Entity
{
public:
	~Entity() = default;
	Entity(Game& game) : game{ game } {}

	virtual void	draw() = 0;
	virtual bool	update(float deltaTime) = 0;

	void			checkCollision(Entity& otherEntity);
	virtual void	onCollision(Entity& otherEntity) {};

	sf::Vector2f	getPosition() { return body.getPosition(); }
	sf::Vector2f	getWindowPosition() { return sf::Vector2f{ body.getPosition().x - game.window.getSize().x / 2, body.getPosition().y - game.window.getSize().y / 2 }; }
	Game&			getGame() { return game; }

protected:
	Game& game;

	sf::CircleShape body;
};

