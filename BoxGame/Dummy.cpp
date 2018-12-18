#include "Dummy.h"
#include "GUI.h"
#include "Damage_Text.h"

Dummy::Dummy(Game& game, sf::Vector2f& position)
	: Enemy{ game, position, sf::Color::Red, 1, 20.0f, 0, 950, 0, "Dummy" }
{								//color, level, size, speed, health, damage, name
										
}

void Dummy::damage_char(int damage)
{
	game.user_interface->add(std::make_unique<Damage_Text>(game, std::to_string(damage), sf::Color::White, body.getPosition()));
}
