#include <string>
#include <sstream>

#include "GUI.h"
#include "Button.h"
#include "Bar.h"

GUI::GUI(Game& game) : Entity{ game }
{
	//healthbar
	shapes.push_back(Bar{game, sf::Vector2f(-200,380), sf::Vector2f(400,20), sf::Color(0,160,0,255)});
	
	//manabar
	shapes.push_back(Bar{game, sf::Vector2f(-170,401), sf::Vector2f(340,15), sf::Color(0,0,160,255)});

	// box displaying Q, W, E, and R-attack
	shapes.push_back(Button{ game, "Q", sf::Vector2f(160, 320) });
	shapes.push_back(Button{ game, "W", sf::Vector2f(160, 320) });
	shapes.push_back(Button{ game, "E", sf::Vector2f(160, 320) });
	shapes.push_back(Button{ game, "R", sf::Vector2f(160, 320) });

	//health text
	sf::Text healthtext;
	healthtext.setFont(courier_font);
	healthtext.setCharacterSize(16);
	healthtext.setFillColor(sf::Color::Black);
	healthtext.setPosition(sf::Vector2f(-50, 380));
	healthtext.setString("100 / 100");
	Texts.push_back(healthtext);
}

void GUI::draw()
{
	for (GUI& shape : shapes)
	{
		shape.draw();
	}
	
	for (sf::Text& Text : Texts)
	{
		game.window.draw(Text);
	}
}

bool GUI::update(float deltaTime) 
{	
	for (GUI& shape : shapes)
	{
		shape.update(deltaTime);
	}

	return false; 
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

