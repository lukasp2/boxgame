#include "Kills_Text.h"
#include "Hero.h"

bool Kills_Text::update()
{
	text.setString("kills: " + std::to_string(game.player->get_kills()));

	return false;
}
