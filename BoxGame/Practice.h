#pragma once
#include "Game.h"

class Practice : public Game
{
public:
	~Practice();
	Practice(sf::RenderWindow& window);

	void	process_input() override;
	State*	update()		override;
	void	render()		override;
};

