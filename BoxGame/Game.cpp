#include <iostream> // cerr

#include "Game.h"
#include "Game_Over.h"
#include "Menu.h"
#include "Quit.h"
#include "Pause.h"

#include "Entity.h"
#include "Hero_1.h"
#include "Warrior.h"
#include "Ranger.h"
#include "Appearing_Character.h"

#include "GUI.h"
#include "Wave_Text.h"

Game::~Game() {}

Game::Game(sf::RenderWindow& window) : State{ window }
{
	read_options();

	read_settings();
	
	open_spawn_file("spawns.txt");

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
	deltaTime = frame_clock.restart().asSeconds();

	if (deltaTime > 1.0f / 20.0f)
	{
		deltaTime = 1.0f / 20.0f;
	}

	if (check_state())
	{
		return state_ptr.get();
	}
	
	check_spawns();

	update_entities();
	
	add_entities();
	
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

bool Game::check_state()
{
	if (option.pause)
	{
		option.pause = false;

		render();
		state_ptr = std::make_unique<Pause>(window, this);
		return true;
	}

	else if (option.quit)
	{
		state_ptr = std::make_unique<Quit>(window);
		return true;
	}

	else if (player->getHealth() <= 0)
	{
		render();
		state_ptr = std::make_unique<Game_Over>(window);
		return true;
	}

	return false;
}

void Game::update_entities()
{
	for (auto it = entities.begin(); it != entities.end(); )
	{
		// collision
		for (auto it2 = entities.begin(); it2 != entities.end(); ++it2)
		{
			if (it2 != it)
			{
				((*it)->checkCollision(*(*it2)));
			}
		}

		// movement
		if ((*it)->update(deltaTime))
		{
			it = entities.erase(it);
		}
		else
		{
			it++;
		}
	}
}

// add new entities to entity vector
void Game::add_entities()
{
	while (!add_queue.empty())
	{
		entities.push_back(add_queue.front());
		add_queue.pop();
	}
}

// add entites to queue
void Game::add(std::shared_ptr<Entity> ptr)
{
	add_queue.push(ptr);
}

// open the file specifying spawns
void Game::open_spawn_file(std::string file)
{
	spawn_stream.open(file);

	if (!spawn_stream)
	{
		std::cerr << "unable to open " + file;
		exit(1);
	}

	spawn_stream >> next_spawn;
}

// check if new enemies should be added or level is complete
void Game::check_spawns()
{
	bool complete{ level_complete() };

	if (!complete && next_spawn < spawn_clock.getElapsedTime().asSeconds() && next_spawn >= 0)
	{
		spawn_enemy();
	}
	else if (complete)
	{
		next_wave();
	}
}

// initiates the next wave of enemies
void Game::next_wave()
{
	std::string wave;
	std::getline(spawn_stream, wave);
	
	user_interface->add(std::make_unique<Wave_Text>(*this, wave));
	user_interface->incWave();

	spawn_clock.restart();

	spawn_stream >> next_spawn;
}

// spawns an enemy
void Game::spawn_enemy()
{
	// format: "5 sec: Warrior lvl 1 @ 100, 200"

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

	// the location on which the enemy should spawn
	float place{};				
	sf::Vector2f pos{};
	spawn_stream >> place;
	pos.x = place;
	spawn_stream >> junk;
	spawn_stream >> place;
	pos.y = place;
	
	if (enemy_type == "Warrior")
	{
		add(std::make_shared<Appearing_Character>(std::make_unique<Warrior>(*this, pos, level)));
	}

	else if (enemy_type == "Ranger")
	{
		add(std::make_shared<Appearing_Character>(std::make_unique<Ranger>(*this, pos, level)));
	}

	 spawn_stream >> next_spawn;
}

// checks if all enemies are killed
bool Game::level_complete() 
{
	// all enemies in the waves has spawned
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

		// no enemies are left on the screen
		if (enemy_count == 0)
		{
			int appearing_count{};

			for (auto&& it : entities)
			{
				if (Appearing_Character* e = dynamic_cast<Appearing_Character*>(&(*it)))
				{
					appearing_count++;
				}
			}
			
			// no enemy is currently spawning
			return appearing_count == 0;
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
