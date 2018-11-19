#include "Game.h"

#include <memory>
#include "Menu.h"
#include "Quit.h"

void Game::process_input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) 
		option.pause = true; 

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
		//player.Q();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W));
		//player.W();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E));
		//player.E();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R));
		//player.R();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::Q));
		//player.upgrade_Q();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::W));
		//player.upgrade_W();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::E));
		//player.upgrade_E();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) && sf::Keyboard::isKeyPressed(sf::Keyboard::R));
		//player.upgrade_R();

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab));
		//show map

	//player.update(); move player
	//if (player.dead == true)
	//	return GameOver;
}

State * Game::update()
{
	/*PREVENTS A BUG*/
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 20.0f) 
		deltaTime = 1.0f / 20.0f;

	if (option.pause)
	{
		option.pause = false;
		//return pauseState;
	}

	if (option.quit)
	{
		option.quit = false;
		state_ptr = std::make_unique<Quit>();
		return state_ptr.get();
	}

	return nullptr;
}

void Game::render(sf::RenderWindow & window)
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::Closed:
			option.quit = true;
			break;
		case sf::Event::Resized:
			float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
			view.setSize(VIEW_SIZE * aspectRatio, VIEW_SIZE);
			break;
		}
	}

	window.clear(sf::Color::Black);
	window.setView(view);

	//DRAWS//
	//player.draw(window);
}
