#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "GUI_Object.h"
#include "Abilities.h"

class Button : public GUI_Object
{
public:
	Button(Game& game, std::string attackName, sf::Vector2f position, ability& ability);

	void draw() override;

	// update: updates the cooldown visual
	void update() override;

	// proccess_input: handles use and upgrade of ability, sets cooldown
	virtual void proccess_input(sf::Event::KeyEvent event) override;

	void upgrade_avalible();

private:
	std::vector<sf::RectangleShape> shapes;
	sf::Text attack_name;

	ability& ability;
};
