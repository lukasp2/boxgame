#include "Game_Over.h"
#include "Text.h"
#include "Main_Menu.h"
#include "Quit.h"
#include <iostream>

#define X_POS -50.0f
#define Y_POS -100.0f
#define CHAR_SIZE 20

Game_Over::Game_Over(sf::RenderWindow& window)
	: Menu{ window }, clock {}
{
	header.setFont(courier_font);
	header.setCharacterSize(CHAR_SIZE);
	header.setString("Game Over");
	header.setFillColor(sf::Color(0,255,0,0));
	header.setPosition(X_POS, Y_POS);

	sf::Text opt;
	opt.setFont(courier_font);
	opt.setCharacterSize(CHAR_SIZE);
	opt.setString("Restart");
	opt.setFillColor(sf::Color(255,255,255,0));
	opt.setPosition(X_POS - 200, Y_POS + 100);
	textVector.push_back(opt);

	opt.setString("Main Menu");
	opt.setFillColor(sf::Color(0, 255, 0, 0));
	opt.setPosition(X_POS, Y_POS + 100);
	textVector.push_back(opt);

	opt.setString("Quit");
	opt.setFillColor(sf::Color(0, 255, 0, 0));
	opt.setPosition(X_POS + 200, Y_POS + 100);
	textVector.push_back(opt);
}

void Game_Over::process_input()
{
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			option.quit = true;
			break;

		case sf::Event::Resized:
			aspectRatio = float(window.getSize().x) / float(window.getSize().y);
			view.setSize(VIEW_SIZE * aspectRatio, VIEW_SIZE);
			break;

		case sf::Event::KeyPressed:
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Left:
				moveUp();
				break;
			case sf::Keyboard::Right:
				moveDown();
				break;
			case sf::Keyboard::Enter:
				switch (selection)
				{
				case 0:
					option.restart = true;
					break;
				case 1:
					option.back_to_main = true;
					break;
				case 2:
					option.quit = true;
					break;
				}
			}
		}
		break;
		}
	}
}

State* Game_Over::update()
{
	if (option.restart)
	{
		//state_ptr->Game::player = std::make_unique<Hero_1>(*state_ptr);
		state_ptr = std::make_unique<Game>(window);
		return state_ptr.get();
	}

	if (option.back_to_main)
	{
		state_ptr = std::make_unique<Main_Menu>(window);
		return state_ptr.get();
	}

	if (option.quit)
	{
		state_ptr = std::make_unique<Quit>(window);
		return state_ptr.get();
	}

	if (clock.getElapsedTime().asSeconds() > 1)
	{
		for (sf::Text& t : textVector)
		{
			sf::Color c = t.getFillColor();
		
			if (c.a != 255)
			{
				c.a += b;
			}

			t.setFillColor(c);
		}

	}

	sf::Color c = header.getFillColor();
	
	if (c.a != 255)
	{
		c.a += b;
	}
	
	header.setFillColor(c);
	
	b = !b;

	return nullptr;
}

void Game_Over::render()
{
	window.draw(header);

	for (sf::Text text : textVector)
	{
		window.draw(text);
	}

	window.display();

	window.setView(view);
}
