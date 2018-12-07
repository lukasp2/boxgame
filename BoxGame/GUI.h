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
	std::vector<GUI> shapes;
	std::vector<sf::Text> Texts;

	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};

/*
void update_health(int health);
void update_mana(int mana);
*/