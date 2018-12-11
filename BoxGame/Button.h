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
	bool update() override;
	void proccess_input(sf::Event event) override;
	//void upgrade_avalible();

private:
	struct Options
	{
		bool mana_too_low;
		bool upgrade_unavalible;
		bool upgrade;
		bool use;
	};
	Options option;

	std::vector<sf::RectangleShape> shapes;
	sf::Text attack_name;
	sf::Text mana_costs;

	sf::Keyboard::Key key;
	ability* a;
};
