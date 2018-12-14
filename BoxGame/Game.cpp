#include <iostream>

#include "Game.h"
#include "Menu.h"
#include "Quit.h"
#include "GUI.h"
#include "Wall.h"
#include "Entity.h"
#include "Warrior.h"
#include "Ranger.h"
#include "Hero_1.h"

Game::~Game() {}

Game::Game(sf::RenderWindow& window) : State{ window }
{
	read_options();
	read_settings();
	read_spawns();

	player = std::make_shared<Hero_1>(*this);
	entities.push_back(player);

	user_interface = std::make_unique<GUI>(*this);
}

void Game::process_input()
{
	while (window.pollEvent(event))
	{
		user_interface->proccess_input(event);
		player->proccess_input(event);

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
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
				option.pause = true;
				break;
			}
			break;

		default:
			break;
		}
	}
}

State* Game::update()
{
	// prevents a bug
	deltaTime = frame_clock.restart().asSeconds();
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

	if (player->getHealth() <= 0)
	{
		option.gameover = false;
		// return game over state
	}

	// check if level is not complete and if its time for next spawn
	if (!level_complete() && next_spawn == static_cast<int>(spawn_clock.getElapsedTime().asSeconds()))
	{
		spawn_enemy();
	}

	for (auto it = entities.begin(); it != entities.end(); )
	{
		// check collision
		for (auto it2 = entities.begin(); it2 != entities.end(); ++it2)
		{
			if (it2 != it)
			{
				((*it)->checkCollision(*(*it2)));
			}
		}
		
		// update
		if ((*it)->update(deltaTime))
		{
			it = entities.erase(it);
		}
		else
		{
			it++;
		}
	}

	// add new entities to entity vector
	while (!add_queue.empty())
	{
		entities.push_back(add_queue.front());
		add_queue.pop();
	}

	// update interface
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

void Game::add(std::shared_ptr<Entity> ptr)
{
	add_queue.push(ptr);
}

//////////////

void Game::read_spawns()
{
	spawn_stream.open("spawns.txt");

	if (!spawn_stream)
	{
		std::cerr << "unable to open spawns.txt";
		exit(1);
	}

	spawn_stream >> next_spawn;
}

void Game::spawn_enemy()
{
	// "2 sec: Ranger lvl 11 @ -500, -500"

	// enemy type
	std::string junk{};
	std::string enemy_type{};
	spawn_stream >> junk;
	spawn_stream >> enemy_type;
	spawn_stream >> junk;
	
	// enemy level
	int level;
	spawn_stream >> level;
	spawn_stream >> junk;

	// the location on which the enemy spawns
	float place{};				
	sf::Vector2f pos{};
	spawn_stream >> place;
	pos.x = place;
	spawn_stream >> junk;
	spawn_stream >> place;
	pos.y = place;
	
	if (enemy_type == "Warrior")
	{
		entities.push_back(std::make_unique<Warrior>(*this, pos, level));
	}

	if (enemy_type == "Ranger")
	{
		entities.push_back(std::make_unique<Ranger>(*this, pos, level));
	}

	// get the seconds after which the next enemy will spawn
	spawn_stream >> next_spawn;
}

bool Game::level_complete() 
{
	if (next_spawn == -1)
	{
		int enemy_count{};

		for (auto&& it : entities)
		{
			if (Enemy* e = dynamic_cast<Enemy*>(&(*it)))
			{
				enemy_count++;
			}
		}

		if (enemy_count == 0)
		{
			// level complete
			spawn_clock.restart();
			spawn_stream >> next_spawn;

			return true;
		}
	}

	return false;
}

// for interface manipulation
void Game::read_options()
{
	/*
	std::ifstream inFile;
	inFile.open("options.txt");
	
	if (!inFile)
	{
		std::cerr << "unable to open options.txt";
		exit(1);
	}

	std::string display_option;
	while (inFile >> display_option)
	{
		char yesno;
		inFile >> yesno;
		
		if (display_option == "display_minibar")
		{
			if (yesno == 'Y')
			{
				display_healthbar = true;
			}
			else
			{

			}
		}

		if (display_option == "display_levelbox")
		{

		}

		if (display_option == "display_clock")
		{

		}
	}
	*/
}

// for key bindings
void Game::read_settings()
{

}
