#include "Hero.h"
#include "Game.h"

#include <cmath>

Hero::Hero(Game& game, sf::Color color, float size, int speed, std::string name) 
	: Character{ game, size, speed, 100, name, color }
{
	Character::name.setFillColor(sf::Color::Green);
	Character::name.setCharacterSize(20);
}

bool Hero::update(float deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		changed_movement = true;
		float mouse_posx = sf::Mouse::getPosition(window).x - static_cast<float>(window.getSize().x / 2);
		float mouse_posy = sf::Mouse::getPosition(window).y - static_cast<float>(window.getSize().y / 2);

		seekPosition = sf::Vector2f{ mouse_posx, mouse_posy };
		startPosition = sf::Vector2f{ body.getPosition().x, body.getPosition().y };

		x = 0;
	}
	
	Character::move();

	return health <= 0;
}

void Hero::process_input(sf::Event::KeyEvent event)
{
	switch (event.code)
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
}

void Hero::draw_more()
{
	//window.draw(name);
}