#include <memory>

#include "Game.h"
#include "Main_Menu.h"
#include "Highscore.h"
#include "Quit.h"
#include "Controls.h"

#define X_POS 100.0f
#define Y_POS 0.0f
#define CHAR_SIZE 35

Main_Menu::Main_Menu(sf::RenderWindow& window) 
	: Menu{ window }
{
	header.setFont(courier_font);
	header.setCharacterSize(CHAR_SIZE);
	header.setString("menu");
	header.setFillColor(sf::Color::Green);
	header.setPosition(X_POS, Y_POS);

	sf::Text opt;

	for (size_t i{ 1 }; i < 5; ++i)
	{
		opt = header;
		
		switch (i)
		{
			case 1:
				opt.setString("start game");
				break;
			case 2:
				opt.setString("highscore");
				break;
			case 3:
				opt.setString("controls");
				break;
			case 4:
				opt.setString("quit");
				break;
		}		
		
		if ( i == 1) opt.setFillColor(sf::Color::White);
		else opt.setFillColor(sf::Color::Green);

		opt.setPosition(X_POS, Y_POS + 5 * i + CHAR_SIZE * i);
		
		textVector.push_back(opt);
	}

	menuView.setSize(VIEW_HEIGHT, VIEW_HEIGHT);
}

void Main_Menu::process_input()
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
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
}

State* Main_Menu::update()
{
	if (option.start)
	{
		option.start = false;

		state_ptr = std::make_unique<Game>(window);
		//state_ptr->Game::player = std::make_unique<Hero_1>(*state_ptr);

		return state_ptr.get();
	}

	if (option.highscore)
	{
		option.highscore = false;
		state_ptr = std::make_unique<Highscore>(window);
		return state_ptr.get();
	}

	if (option.controls)
	{
		option.controls = false;
		state_ptr = std::make_unique<Controls>(window);
		return state_ptr.get();
	}

	if (option.quit)
	{
		option.quit = false;
		state_ptr = std::make_unique<Quit>(window);
		return state_ptr.get();
	}

	return nullptr;
}

void Main_Menu::render()
{
	window.clear(sf::Color::Black);
	
	window.draw(header);

	for (sf::Text text : textVector)
	{
		window.draw(text);
	}
	
	window.display();
	
	window.setView(menuView);
}

