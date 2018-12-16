#include "Score_Text.h"
#include "Hero.h"

bool Score_Text::update()
{
	text.setString("score: " + std::to_string(game.player->get_score()));

	return false;
}
