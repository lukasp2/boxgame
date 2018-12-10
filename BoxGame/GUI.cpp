#include <string>
#include <sstream>

#include "GUI.h"
#include "Button.h"
#include "Bar.h"
#include "Hero.h"

GUI::GUI(Game& game) : game{ game }
{
	//healthbar
	bars.push_back( std::make_unique<Bar>(game, sf::Vector2f(-200,380), sf::Vector2f(400,20), sf::Color(0,160,0,255)) );
	
	//manabar
	bars.push_back( std::make_unique<Bar>(game, sf::Vector2f(-170,401), sf::Vector2f(340,15), sf::Color(0,0,160,255)) );

	// box displaying Q, W, E, and R-attack
	buttons.push_back( std::make_unique<Button>(game, "Q", sf::Vector2f(-150, 320)) );
	buttons.push_back( std::make_unique<Button>(game, "W", sf::Vector2f(-70, 320)) );
	buttons.push_back( std::make_unique<Button>(game, "E", sf::Vector2f(10, 320)) );
	buttons.push_back( std::make_unique<Button>(game, "R", sf::Vector2f(90, 320)) );

	//health text
	sf::Text healthtext;
	healthtext.setFont(game.courier_font);
	healthtext.setCharacterSize(16);
	healthtext.setFillColor(sf::Color::Black);
	healthtext.setPosition(sf::Vector2f(-50, 380));
	healthtext.setString("100 / 100");
	texts.push_back(healthtext);
}

void GUI::proccess_input(sf::Event::KeyEvent event)
{
	switch (event.code)
	{
	case sf::Keyboard::Q:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
			upgrade_Q();
		else
			used_Q();
		break;
	case sf::Keyboard::W:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
			upgrade_W();
		else
			used_W();
		break;
	case sf::Keyboard::E:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
			upgrade_E();
		else
			used_E();
		break;
	case sf::Keyboard::R:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt))
			upgrade_R();
		else
			used_R();
		break;
	}

	for (auto&& object : GUI_objects)
	{
		object->process_input(event.code);
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

