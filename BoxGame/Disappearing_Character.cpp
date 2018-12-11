#include "Disappearing_Character.h"

Disappearing_Character::Disappearing_Character(Game& game, sf::CircleShape body, sf::Color color, size_t lifetime)
	: Entity{ game }, body{ body }, lifetime{ lifetime }, total_lifetime{ lifetime }, color{ color }, inner_color{ color - sf::Color(0, 0, 0, 200) }
{
	inner_body = body;
	inner_body.setRadius(body.getRadius() - 3);
	inner_body.setOutlineThickness(8.0f);
	inner_body.setOutlineColor(inner_color);
	inner_body.setPosition(body.getPosition().x + 3, body.getPosition().y + 3);
}

void Disappearing_Character::draw()
{
	game.window.draw(body);
	game.window.draw(inner_body);
}

bool Disappearing_Character::update(float deltaTime)
{
	color.a -= static_cast<sf::Uint8>(255 / total_lifetime);
	body.setOutlineColor(color);
	
	inner_color.a -= static_cast<sf::Uint8>(55 / total_lifetime);
	inner_body.setOutlineColor(inner_color);

	return lifetime-- == 0;
}
