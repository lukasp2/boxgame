#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

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
	std::vector<std::unique_ptr<Entity>> shapes;
	std::vector<sf::Text> Texts;
};

/*
void update_health(int health);
void update_mana(int mana);
*/