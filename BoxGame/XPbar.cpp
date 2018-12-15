#include "XPbar.h"
#include "Hero.h"

bool XPbar::update()
{
	if (game.player->getXP() <= 100)
		bar.setScale(float(game.player->getXP()) / float(100.0), 1);

	return false;
}