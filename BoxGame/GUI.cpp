#include <string>
#include <sstream>

#include "GUI.h"
#include "Button.h"
#include "Healthbar.h"
#include "Mini_Healthbar.h"
#include "Manabar.h"
#include "XPbar.h"
#include "Hero.h"

GUI::GUI(Game& game) : game{ game }
{
	// healthbar
	GUI_Objects.push_back(std::make_unique<Healthbar>(game, sf::Vector2f(-200, 380), sf::Vector2f(400, 20), sf::Color(0,160,0, 255)));
	
	// manabar
	GUI_Objects.push_back(std::make_unique<Manabar>(game, sf::Vector2f(-200, 403), sf::Vector2f(400, 10), sf::Color(0,0,160, 255)));

	// XP-bar
	GUI_Objects.push_back(std::make_unique<XPbar>(game, sf::Vector2f(-200, 375), sf::Vector2f(400, 2), sf::Color(255, 255, 0, 255)));

	// box displaying Q, W, E, and R-attack
	GUI_Objects.push_back( std::make_unique<Button>(game, "Q", sf::Vector2f(-150, 320), game.player->q_ptr, sf::Keyboard::Key::Q) );
	GUI_Objects.push_back( std::make_unique<Button>(game, "W", sf::Vector2f(-70, 320), game.player->w_ptr, sf::Keyboard::Key::W) );
	GUI_Objects.push_back( std::make_unique<Button>(game, "E", sf::Vector2f(10, 320), game.player->e_ptr, sf::Keyboard::Key::E) );
	GUI_Objects.push_back( std::make_unique<Button>(game, "R", sf::Vector2f(90, 320), game.player->r_ptr, sf::Keyboard::Key::R) );

	// mini healthbar
	GUI_Objects.push_back(std::make_unique<Mini_Healthbar>(game, game.player->getPosition(), sf::Vector2f(40, 4), sf::Color(0, 235, 0)));
}

void GUI::proccess_input(sf::Event event)
{
	for (auto&& object : GUI_Objects)
	{
		object->proccess_input(event);
	}
}

void GUI::draw()
{
	for (auto&& object : GUI_Objects)
	{
		object->draw();
	}

	game.window.draw(game.getClock().get_as_text());
}

void GUI::update()
{
	for (auto it = GUI_Objects.begin(); it != GUI_Objects.end(); )
	{
		if ((*it)->update())
		{
			it = GUI_Objects.erase(it);
		}
		else
		{
			++it;
		}
	}
}
