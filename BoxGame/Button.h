#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "GUI_Object.h"
#include "Abilities.h"

class Button : public GUI_Object
{
public:
	Button(Game& game, std::string attackName, sf::Vector2f position, ability* ability, sf::Keyboard::Key key);

	void draw() override;

	void update() override;
	void use();

	virtual void proccess_input(sf::Event event) override;

	void upgrade();
	void upgrade_avalible();

private:
	std::vector<sf::RectangleShape> shapes;
	sf::Text attack_name;

	sf::Keyboard::Key key;
	ability* a;
};
