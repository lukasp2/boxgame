#include "Hero.h"
#include "Game.h"
#include "GUI.h"

#include <iostream>

Hero::Hero(Game& game, sf::Color color, float size, int speed, std::string name) 
	: Character{ game, size, speed, 100, name, color }, XP{ 0 }, mana{ 100 }
{
	Character::name.setFillColor(sf::Color::Green);
	Character::name.setCharacterSize(20);
}

bool Hero::update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		changed_movement = true;
		float mouse_posx = sf::Mouse::getPosition(game.window).x - static_cast<float>(game.window.getSize().x / 2);
		float mouse_posy = sf::Mouse::getPosition(game.window).y - static_cast<float>(game.window.getSize().y / 2);

		seekPosition = sf::Vector2f{ mouse_posx, mouse_posy };
		startPosition = sf::Vector2f{ body.getPosition().x, body.getPosition().y };

		x = 0;
	}
	
	Character::move();

	return health <= 0;
}

void Hero::proccess_input(sf::Event event)
{
	switch (event.type)
	{
	case sf::Event::KeyPressed:
		switch (event.key.code)
		{
		case sf::Keyboard::Q:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				upgrade_Q();
			else
				Q();
			break;
		case sf::Keyboard::W:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				upgrade_W();
			else
				W();
			break;
		case sf::Keyboard::E:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				upgrade_E();
			else
				E();
			break;
		case sf::Keyboard::R:
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
				upgrade_R();
			else
				R();
			break;
		}
	default:
		break;
	}
}

bool Hero::can_upgrade(int& level)
{
	if (level != 4)
	{
		level++;
		upgrades_avalible--;
		return true;
	}

	return false;
}

void Hero::draw_more()
{
	//window.draw(name);
}