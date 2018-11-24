#include "Game.h"

#include <memory>
#include "Menu.h"
#include "Quit.h"
#include "Wall.h"

Game::Game(sf::RenderWindow& window) : State{ window } {}

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
			case sf::Keyboard::Q:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
					player.upgrade_Q();
				else 
					player.Q();
				break;
			case sf::Keyboard::W:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
					player.upgrade_W();
				else
					player.W();
				break;
			case sf::Keyboard::E:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
					player.upgrade_E();
				else
					player.E();
				break;
			case sf::Keyboard::R:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
					player.upgrade_R();
				else
					player.R();
				break;

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
		break;
		}
	}
}

State* Game::update()
{
	/*prevent a bug*/
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 20.0f) deltaTime = 1.0f / 20.0f;

	if (option.pause)
	{
		option.pause = false;
		//return pauseState;
	}

	if (option.quit)
	{
		option.quit = false;
		state_ptr = std::make_unique<Quit>(window);
		return state_ptr.get();
	}

	player.update(deltaTime);
	if (player.death_check()) {}

	/*
	///////////////////////PROJECTILE COLLISION WITH WALLS///////////////////////////////
	for (auto pit = player.q.projectiles.begin(); pit != player.q.projectiles.end())
	{
		Collider projCol = pit->GetCollider();
		
		for (Wall& wall : Wall::walls)
		{
			//Projectile hits wall			
			if (wall.GetCollider().CheckCollision(projCol, pit->getColDirection(), 1.0f))
				pit = player.q.projectiles.erase(pit);

			else
				pit++;
		}

		//Projectile is updated and erased after some time
		if (pit->update(deltaTime, player.getRange()))
			pit = player.projectiles.erase(pit);

	}
	/////////////////////////////////////////////////////////////////////////////////////
	*/
	

	return nullptr;
}

void Game::render()
{
	window.clear(sf::Color::Black);
	window.setView(view);

	player.draw();

	window.display();
}
