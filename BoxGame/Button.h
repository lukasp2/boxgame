#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

#include "Game.h"
#include "GUI.h"

class Button : public GUI
{
public:
	Button(Game& game, std::string attackName, sf::Vector2f position);

	void draw() override;
	bool update(float deltaTime) override;

private:
	std::vector<sf::RectangleShape> shapes;
	sf::Text attack_name;
	int effect_counter;
};
