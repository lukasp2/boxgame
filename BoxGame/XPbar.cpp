#include "XPbar.h"
#include "Hero.h"

bool XPbar::update()
{
	bar.setScale(float(game.player->getXP()) / float(100.0), 1);

	return false;
}