#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <string>

#include "Resources.h"

class State
{
public:
	State() = delete;
	~State() = default;

	State(sf::RenderWindow& window) : window { window } {}

	virtual void process_input() = 0;
	virtual State* update() = 0;
	virtual void render() = 0;

	sf::RenderWindow& window;

protected:
	std::unique_ptr<State> state_ptr;
};

/*
nice alias to use:
template <typename T>
using ptr = std::unique_ptr<T>;
*/

