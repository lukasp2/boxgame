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

protected:
	std::unique_ptr<State> state_ptr;
	sf::RenderWindow& window;
};

/*
nice alias to use:
template <typename T>
using ptr = std::unique_ptr<T>;
*/

