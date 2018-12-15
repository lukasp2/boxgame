#include "Appearing_Character.h"
#include "Mini_Healthbar.h"
#include "Level_Box.h"
#include "Enemy_Name.h"
#include "GUI.h"

Appearing_Character::Appearing_Character(std::shared_ptr<Character> character)
	: Entity{ character->getGame() }, character{ character }, intended_radius{ this->character->getRadius() }
{
	character->setRadius(0.0f);
}

bool Appearing_Character::update(float deltaTime)
{
	character->setRadius(character->getRadius() + 0.1f);
	
	if (character->getRadius() > intended_radius)
	{
		character->setRadius(intended_radius);		
		character->getGame().user_interface->add(std::make_unique<Mini_Healthbar>(game, *character, sf::Vector2f(45, 4), sf::Color::Red));
		character->getGame().user_interface->add(std::make_unique<Level_Box>(game, *character));
		character->getGame().user_interface->add(std::make_unique<Enemy_Name>(game, *character));

		game.add(character);

		return true;
	}

	return false;
}

void Appearing_Character::draw()
{
	game.window.draw(character->getBody());
}