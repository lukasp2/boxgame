#include <memory>

#include "Main_Menu.h"
#include "Game.h"
#include "Highscore.h"
#include "Quit.h"
#include "helps.h"
#include "Controls.h"

#define X_POS 100.0f
#define Y_POS 0.0f
#define CHAR_SIZE 35

Main_Menu::Main_Menu()
{
	header = text_processor(CHAR_SIZE, "menu", sf::Color::Green, sf::Vector2f(X_POS, Y_POS), "Fonts/courier.ttf");

	textVector.push_back(text_processor(CHAR_SIZE, "start game", sf::Color::White, sf::Vector2f(X_POS, Y_POS + 10 + CHAR_SIZE * 1), "Fonts/courier.ttf"));
	textVector.push_back(text_processor(CHAR_SIZE, "highscore", sf::Color::Green, sf::Vector2f(X_POS, Y_POS + 20 + CHAR_SIZE * 2), "Fonts/courier.ttf"));
	textVector.push_back(text_processor(CHAR_SIZE, "controls", sf::Color::Green, sf::Vector2f(X_POS, Y_POS + 30 + CHAR_SIZE * 3), "Fonts/courier.ttf"));
	textVector.push_back(text_processor(CHAR_SIZE, "quit", sf::Color::Green, sf::Vector2f(X_POS, Y_POS + 40 + CHAR_SIZE * 4), "Fonts/courier.ttf"));

	menuView.setSize(VIEW_HEIGHT, VIEW_HEIGHT);
}

void Main_Menu::process_input()
{

}

State* Main_Menu::update()
{
	if (option.start)
	{
		option.start = false;
		state_ptr = std::make_unique<Game>();
		return state_ptr.get();
	}

	if (option.highscore)
	{
		option.highscore = false;
		state_ptr = std::make_unique<Highscore>(this);
		return state_ptr.get();
	}

	if (option.controls)
	{
		option.controls = false;
		state_ptr = std::make_unique<Controls>(this);
		return state_ptr.get();
	}

	if (option.quit)
	{
		option.quit = false;
		state_ptr = std::make_unique<Quit>();
		return state_ptr.get();
	}

	return nullptr;
}

void Main_Menu::render(sf::RenderWindow & window)
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
			case sf::Event::KeyReleased:
			{
				switch (evnt.key.code)
				{
				case sf::Keyboard::Up:
					moveUp();
					break;
				case sf::Keyboard::Down:
					moveDown();
					break;
				case sf::Keyboard::Enter:
					switch (selection)
					{
					case 0:
						option.start = true;
						break;
					case 1:
						option.highscore = true;
						break;
					case 2:
						option.controls = true;
						break;
					case 3:
						option.quit = true;
						break;
					}
				}
			}
			break;
		}
	}

	window.clear(sf::Color::Black);
	
	window.draw(header);
	for (sf::Text text : textVector)
		window.draw(text);
	
	window.display();
	
	window.setView(menuView);
}

