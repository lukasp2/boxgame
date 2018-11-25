#pragma once
#include <SFML/Graphics.hpp>

#include "Resources.h"

class Drawable
{
public:
	~Drawable() = default;
	Drawable(sf::RenderWindow& window) : window{ window } { }

	virtual void draw() = 0;

protected:
	sf::RenderWindow& window;
};

