#include "Damage_Text.h"

bool Damage_Text::update()
{
	Fading_Text::update();

	text.setPosition(text.getPosition().x, text.getPosition().y - 0.1f );

	return false;
}
