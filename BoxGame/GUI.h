#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Entity.h"
#include "Game.h"

class GUI : public Entity
{
public:
	GUI(Game& game);

	void draw() override;
	bool update(float deltaTime) override;

	void update_health(int health);
	void update_mana(int mana);

	void used_Q();
	void used_W();
	void used_E();
	void used_R();

	void upgraded_Q(int to_level);
	void upgraded_W(int to_level);
	void upgraded_E(int to_level);
	void upgraded_R(int to_level);

private:
	std::vector<sf::RectangleShape> RecShapes;
	std::vector<sf::Text> Texts;
};
