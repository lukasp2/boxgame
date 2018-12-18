#include <iostream> // cerr

#include "Menu.h"
#include "Quit.h"
#include "Practice.h"

#include "Entity.h"
#include "Hero_1.h"
#include "Appearing_Character.h"
#include "Dummy.h"

#include "GUI.h"
#include "Wave_Text.h"

Practice::~Practice() {}

Practice::Practice(sf::RenderWindow& window) 
	: Game{ window }
{
	spawn_stream.close();

	sf::Vector2f position{ 0, -300 };

	add(std::make_shared<Appearing_Character>(std::make_unique<Dummy>(*this, position)));
}

void Practice::process_input()
{
	Game::process_input();
}

State * Practice::update()
{
	return Game::update();
}

void Practice::render()
{
	Game::render();
}