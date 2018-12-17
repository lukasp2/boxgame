#include "Appearing_Character.h"
#include "Mini_Healthbar.h"
#include "Level_Box.h"
#include "Enemy_Name.h"
#include "GUI.h"

Appearing_Character::Appearing_Character(std::shared_ptr<Character> character)
	: Entity{ character->getGame() }, character{ character }
{
	body = character->getBody();
	body.setRadius(0.0f);
}

bool Appearing_Character::update(float deltaTime)
{
	body.setRadius(body.getRadius() + 0.1f);
	body.setOrigin(body.getRadius(), body.getRadius());

	if (body.getRadius() > character->getRadius())
	{
		//user_interface.add(Character& character)
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
	game.window.draw(body);//character->getBody());
}