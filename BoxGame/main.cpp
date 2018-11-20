#include <SFML/Graphics.hpp>

#include "Resources.h"
#include "Main_Menu.h"
#include "State.h"
#include "Quit.h"

int main()
{
	sf::RenderWindow window{ sf::VideoMode(900, 900), "Game", sf::Style::Default };

	window.setFramerateLimit(144);

	std::unique_ptr<Menu> mainMenu = std::make_unique<Main_Menu>();
	State* currentState{ mainMenu.get() };

	State* nextState;

	while (true)
	{
		currentState->process_input(window);

		if (nextState = currentState->update(window))
			currentState = nextState;

		if (dynamic_cast<Quit*>(currentState))
			break;
	
		currentState->render(window);
	}

	return 0;
}