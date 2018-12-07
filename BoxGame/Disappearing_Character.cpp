#include "Disappearing_Character.h"

Disappearing_Character::Disappearing_Character(Game & game, sf::CircleShape body, sf::Color color, size_t lifetime)
	: Entity{ game }, body{ body }, lifetime{ lifetime }, total_lifetime{ lifetime }, color{ color }
{

}

bool Disappearing_Character::update(float deltaTime)
{
	color.a -= static_cast<sf::Uint8>(255 / total_lifetime);
	body.setOutlineColor(sf::Color(color));

	return lifetime-- == 0;
}
