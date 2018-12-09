#include "Game.h"
#include "Menu.h"
#include "Quit.h"

#include "GUI.h"
#include "Wall.h"
#include "Entity.h"
#include "Warrior.h"
#include "Hero_1.h"

Game::~Game() {}

Game::Game(sf::RenderWindow& window) : State{ window }
{
	player = std::make_shared<Hero_1>(*this);
	entities.push_back( player );

	user_interface = std::make_unique<GUI>(*this);
}

void Game::process_input()
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			option.quit = true;
			break;

		case sf::Event::Resized:
			aspectRatio = float(window.getSize().x) / float(window.getSize().y);
			view.setSize(VIEW_SIZE * aspectRatio, VIEW_SIZE);
			break;

		case sf::Event::KeyPressed:
			switch (evnt.key.code)
			{
			case sf::Keyboard::Tab:
				//show map
				break;

			case sf::Keyboard::F:
				//action key
				break;

			case sf::Keyboard::Escape:
				option.pause = true;
				break;
			}
			
			player->process_input(evnt.key);
			
			break;

		default:
			break;
		}
	}
}

State* Game::update()
{
	// prevents a bug
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 20.0f)
	{
		deltaTime = 1.0f / 20.0f;
	}

	if (option.pause)
	{
		option.pause = false;
		// return pauseState;
	}

	if (option.quit)
	{
		option.quit = false;
		state_ptr = std::make_unique<Quit>(window);
		return state_ptr.get();
	}
	
	// do this in player::update() by setting gameover = true from there.
	if (option.gameover)
	{
		option.gameover = false;
		// return game over state
	}

	for (auto it = entities.begin(); it != entities.end(); )
	{
		if ((*it)->update(deltaTime))
		{
			it = entities.erase(it);
		}
		else
		{
			it++;
		}
	}

	user_interface->update();

	return nullptr;
}

void Game::render()
{
	window.clear(sf::Color::Black);
	
	window.setView(view);

	for (auto&& entity : entities)
	{
		entity->draw();
	}

	user_interface->draw();

	window.display();
}
