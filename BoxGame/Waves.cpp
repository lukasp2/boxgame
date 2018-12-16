#include "Waves.h"
#include "GUI.h"
#include <iostream>

bool Waves::update()
{
	if (game.user_interface->getWave() > current_wave)
	{
		clock.restart();
		current_wave++;
		increment_wave = true;
	}

	if (increment_wave && clock.getElapsedTime().asSeconds() > 4)
	{
		text.setString("Wave: " + std::to_string(current_wave));
		increment_wave = false;
	}

	return false;
}
