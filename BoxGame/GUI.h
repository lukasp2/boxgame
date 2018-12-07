#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"
#include "Game.h"

class GUI : public Entity
{
public:
	GUI(Game& game);
	~GUI() = default;

	virtual void draw() override;
	virtual bool update(float deltaTime) override;

protected:
	std::vector<Entity> shapes;
	std::vector<sf::Text> Texts;
};

/*
void update_health(int health);
void update_mana(int mana);
*/