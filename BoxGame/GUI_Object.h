#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

class GUI_Object
{
public:
	GUI_Object(Game& game) : game{ game } {}
	~GUI_Object() = default;

	virtual void draw() = 0;
	virtual void update() = 0;

protected:
	Game& game;
};

