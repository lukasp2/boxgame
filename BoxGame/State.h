#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <string>

#include "Resources.h"

class State
{
public:
	~State() = default;

	virtual void process_input(sf::RenderWindow& window) = 0;
	virtual State* update(sf::RenderWindow& window) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

protected:
	std::unique_ptr<State> state_ptr;

	// a queue of states
	std::stack<std::unique_ptr<State>> states;
};

/*
nice alias to use:
template <typename T>
using ptr = std::unique_ptr<T>;
*/

