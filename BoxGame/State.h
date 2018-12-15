#pragma once
#include <SFML/Graphics.hpp>
#include <stack>
#include <string>

#include "Resources.h"

static const float VIEW_SIZE{ 900.0f };

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

	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };

protected:
	sf::Event	event;
	sf::View	view{ sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE) };
	float		aspectRatio;

	std::unique_ptr<State> state_ptr;
};

/*
template <typename T>
using u_ptr = std::unique_ptr<T>;

template <typename T>
using make_ptr = std::make_unique<T>;
*/

