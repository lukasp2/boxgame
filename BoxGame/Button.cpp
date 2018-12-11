#include "Button.h"
#include "Hero.h"

#include <iostream>

Button::Button(Game& game, std::string attackName, sf::Vector2f position, ability* a, sf::Keyboard::Key key)
	: GUI_Object{ game }, a{ a }, key { key }
{
	// the big box
	sf::RectangleShape big_box;
	big_box.setSize(sf::Vector2f(40, 40));
	big_box.setPosition(position.x, position.y);
	big_box.setFillColor(sf::Color(15,15,15));
	big_box.setOutlineColor(sf::Color(30,30,30));
	big_box.setOutlineThickness(1.0f);
	shapes.push_back(big_box);

	// the visualeffect of the cooldown
	sf::RectangleShape cd_box;
	cd_box.setSize(sf::Vector2f(38, 38));
	cd_box.setPosition(position.x + 1, position.y + 1);
	cd_box.setFillColor(sf::Color(15,15,15)); // set to 35,35,35
	shapes.push_back(cd_box);

	// the smaller boxes
	for (int i{}; i < 4; ++i)
	{
		sf::RectangleShape small_box;
		small_box.setSize(sf::Vector2f(5, 5));
		small_box.setPosition( position.x + 2 + i * 10, position.y + big_box.getSize().y - 7);
		small_box.setFillColor(sf::Color::Black);
		small_box.setOutlineColor(sf::Color::White);
		small_box.setOutlineThickness(1.0f);
		shapes.push_back(small_box);
	}

	// the text
	attack_name.setFont(game.courier_font);
	attack_name.setCharacterSize(18);
	attack_name.setPosition(sf::Vector2f(position.x + big_box.getSize().x / 2 - 5, position.y + big_box.getSize().y / 2 - 16));
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
	if (game.player->upgrades_avalible > 0)
	{
		// set outline color
	}

	//update cooldown thingy
}

void Button::upgrade()
{
	if (game.player->upgrades_avalible > 0 && a->level < 4)
	{
		shapes[a->level + 2].setFillColor(sf::Color::Yellow);
		shapes[0].setOutlineColor(sf::Color(120, 100, 0));
	}
	else if (game.player->upgrades_avalible < 2)
	{
		shapes[0].setOutlineColor(sf::Color::Red);
		// "upgrade unavalible"
	}
	else if (a->level == 4)
	{
		shapes[0].setOutlineColor(sf::Color::Red);
		// "ability is already at maximum level"
	}
	else
	{
		shapes[0].setOutlineColor(sf::Color::Red);
		// "no upgrades"
	}
}

void Button::use()
{
	if (game.player->mana >= a->mana_cost) // && a->cooldown_count == 0 // sf::Time cooldown_count;
	{
		shapes[0].setOutlineColor(sf::Color(100,100,100));
	}
	else if (game.player->mana < a->mana_cost)
	{
		shapes[0].setOutlineColor(sf::Color(50, 0, 0));
		// "mana too low"
	}
	/*
	else if (game.player->cooldown < a->cooldown)
	{
		shapes[0].setOutlineColor(sf::Color(50, 0, 0));
		// "ability not ready yet"
	}
	*/
}

void Button::proccess_input(sf::Event event)
{
	shapes[0].setOutlineColor(sf::Color(30, 30, 30));
	
	if (sf::Keyboard::isKeyPressed(key) && sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
	{
		upgrade();
	}
	else if (sf::Keyboard::isKeyPressed(key))
	{ 
		use();
	}
}

void Button::upgrade_avalible()
{

}