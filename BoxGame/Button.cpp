#include "Button.h"

Button::Button(Game& game, std::string attackName, sf::Vector2f position, ability& ability)
	: GUI_Object{ game }, ability{ ability }
{
	// the big box
	sf::RectangleShape shape;
	shape.setSize(sf::Vector2f(40, 40));
	shape.setPosition(position.x, position.y);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineColor(sf::Color::White);
	shape.setOutlineThickness(1.0f);
	shapes.push_back(shape);

	// the smaller boxes
	for (int i{}; i < 4; ++i)
	{
		sf::RectangleShape small_box;
		small_box.setSize(sf::Vector2f(5, 5));
		small_box.setPosition( position.x + 2 + i * 10, position.y + shape.getSize().y - 7);
		small_box.setFillColor(sf::Color::Black);
		small_box.setOutlineColor(sf::Color::White);
		small_box.setOutlineThickness(1.0f);
		shapes.push_back(small_box);
	}

	// the text
	attack_name.setFont(game.courier_font);
	attack_name.setCharacterSize(18);
	attack_name.setPosition(sf::Vector2f(position.x + shape.getSize().x / 2 - 5, position.y + shape.getSize().y / 2 - 16));
	attack_name.setString(attackName);
}

void Button::draw()
{
	for (auto&& shape : shapes)
	{
		game.window.draw(shape);
	}

	game.window.draw(attack_name);
}

void Button::update()
{
	//update cooldown thingy
}

void Button::upgrade()
{
	if (game.player->upgrades_avalible > 0 && ability.level != 4)
	{
		// *upgrade*
	}
	else if (game.player->upgrades_avalible == 0)
	{
		// "upgrade unavalible"
	}
	else if (ability.level > 4)
	{
		// "ability is already at maximum level"
	}
}

void Button::proccess_input(sf::Event::KeyEvent event)
{
	// skicka in Knapp till kontruktorn
	switch (event.code)
	{
	case sf::Keyboard::Q:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
			upgrade_Q();
		else
			used_Q();
		break;
	}
}

void Button::upgrade_avalible()
{
}
