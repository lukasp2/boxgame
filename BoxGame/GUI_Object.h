#pragma once
#include <SFML/Graphics.hpp>
#include "State.h"

class GUI_Object
{
public:
	GUI_Object(State& state) : state{ state } {}
	~GUI_Object() = default;

	virtual void draw() = 0;
	virtual void update() = 0;

protected:
	State& state;
};

