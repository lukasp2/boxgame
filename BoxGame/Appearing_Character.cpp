#include "Appearing_Character.h"
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
		game.user_interface->add(*character);
		game.add(character);

		return true;
	}

	return false;
}

void Appearing_Character::draw()
{
	game.window.draw(body);
}