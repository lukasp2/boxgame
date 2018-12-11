#include "Manabar.h"
#include "Hero.h"

bool Manabar::update()
{
	bar.setScale(game.player->getMana() / float(100.0), 1);

	return false;
}
