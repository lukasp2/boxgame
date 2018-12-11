#include <string>
#include <sstream>

#include "GUI.h"
#include "Button.h"
#include "Bar.h"
#include "Hero.h"

GUI::GUI(Game& game) : game{ game }
{
	//healthbar
	GUI_Objects.push_back( std::make_unique<Bar>(game, sf::Vector2f(-200, 380), sf::Vector2f(400, 20), sf::Color(0,160,0, 255)) );
	
	//manabar
	GUI_Objects.push_back( std::make_unique<Bar>(game, sf::Vector2f(-170, 403), sf::Vector2f(340, 10), sf::Color(0,0,160, 255)) );

	//XP-bar
	GUI_Objects.push_back(std::make_unique<Bar>(game, sf::Vector2f(-200, 375), sf::Vector2f(400, 2), sf::Color(255, 255, 0, 255)));

	// box displaying Q, W, E, and R-attack
	GUI_Objects.push_back( std::make_unique<Button>(game, "Q", sf::Vector2f(-150, 320), game.player->q_ptr, sf::Keyboard::Key::Q) );
	GUI_Objects.push_back( std::make_unique<Button>(game, "W", sf::Vector2f(-70, 320), game.player->w_ptr, sf::Keyboard::Key::W) );
	GUI_Objects.push_back( std::make_unique<Button>(game, "E", sf::Vector2f(10, 320), game.player->e_ptr, sf::Keyboard::Key::E) );
	GUI_Objects.push_back( std::make_unique<Button>(game, "R", sf::Vector2f(90, 320), game.player->r_ptr, sf::Keyboard::Key::R) );

	//health text
	sf::Text healthtext;
	healthtext.setFont(game.courier_font);
	healthtext.setCharacterSize(16);
	healthtext.setFillColor(sf::Color::Black);
	healthtext.setPosition(sf::Vector2f(-50, 380));
	healthtext.setString("100 / 100");
	texts.push_back(healthtext);
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

	for (sf::Text& text : texts)
	{
		game.window.draw(text);
	}
}

void GUI::update()
{
	for (auto&& object : GUI_Objects)
	{
		object->update();
	}
}

/*
void GUI::update_health(int health)
{
	RecShapes[0].setScale(health / float(100.0), 1);

	std::stringstream ss{ health };
	Texts[4].setString(ss.str() + " / 100");
}

void GUI::update_mana(int mana)
{
	RecShapes[2].setScale(mana / float(100.0), 1);
	
	std::stringstream ss{ mana };
	Texts[4].setString(ss.str() + " / 100");
}
*/

