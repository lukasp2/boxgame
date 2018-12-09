#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

#include "State.h"
#include "GUI_Object.h"

class GUI
{
public:
	GUI(State& state);
	~GUI() = default;

	//denna klass är friendad i Hero

	//ritar ut och updaterar alla GUI_Objects i vectorn
	void draw();
	void update();

protected:
	std::vector<std::unique_ptr<GUI_Object>> shapes;
	std::vector<sf::Text> texts;

	State& state;
};