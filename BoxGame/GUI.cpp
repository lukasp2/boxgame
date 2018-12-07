#include "GUI.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <sstream>

GUI::GUI(Game & game) : Entity{ game }
{
	for (int i{}; i < 25; ++i)
		RecShapes.push_back(sf::RectangleShape{});

	// healthbar
	RecShapes[0].setSize				(sf::Vector2f(400, 20));
	RecShapes[0].setPosition			(-200, 380);
	RecShapes[0].setFillColor			(sf::Color(0,160,0,255)); // green

	// edge of healthbar
	RecShapes[1].setSize				(sf::Vector2f(400, 20));
	RecShapes[1].setPosition			(-200, 380);
	RecShapes[1].setFillColor			(sf::Color::Transparent);
	RecShapes[1].setOutlineColor		(sf::Color::White);
	RecShapes[1].setOutlineThickness	(1.0f);

	// manabar
	RecShapes[2].setSize				(sf::Vector2f(340, 15));
	RecShapes[2].setPosition			(-170,401);
	RecShapes[2].setFillColor			(sf::Color(0,0,160,255));
	
	// edge of manabar
	RecShapes[3].setSize				(sf::Vector2f(340, 15));
	RecShapes[3].setPosition			(-170, 401);
	RecShapes[3].setFillColor			(sf::Color::Transparent);
	RecShapes[3].setOutlineColor		(sf::Color::White);
	RecShapes[3].setOutlineThickness	(1.0f);

	// box displaying Q, W, E, and R-attack
	for (int i{ 4 }; i < 8; ++i)
	{
		RecShapes[i].setSize			(sf::Vector2f(40, 40));
		RecShapes[i].setPosition		(float(-400 + 70 * i), 320.0f);
		RecShapes[i].setFillColor		(sf::Color::Black);
		RecShapes[i].setOutlineColor	(sf::Color::White);
		RecShapes[i].setOutlineThickness(1.0f);
	}

	/*
	for (int i{ 8 }; i < 24; ++i)
	{
		RecShapes[i].setSize			(sf::Vector2f(5, 5));
		RecShapes[i].setPosition		(float(-968 + 100 * i + 10 * k), 332.0f);
		RecShapes[i].setFillColor		(sf::Color::Black);
		RecShapes[i].setOutlineColor	(sf::Color::White);
		RecShapes[i].setOutlineThickness(1.0f);
	}
	*/

	for (int k{}; k < 4; ++k)
	{
		for (int i{ 8 }; i < 12; ++i)
		{
			RecShapes[4 * k + i].setSize(sf::Vector2f(5, 5));
			RecShapes[4 * k + i].setPosition(float(-677 + 70 * i + 10 * k), 350.0f);
			RecShapes[4 * k + i].setFillColor(sf::Color::Black);
			RecShapes[4 * k + i].setOutlineColor(sf::Color::White);
			RecShapes[4 * k + i].setOutlineThickness(1.0f);
		}
	}

	RecShapes.shrink_to_fit();

	///// Texts //////
	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };

	for (int i{}; i < 10; ++i)
		Texts.push_back(sf::Text{});

	// Q W E R
	for (int i{}; i < 4; ++i)
	{
		Texts[i].setFont(courier_font);
		Texts[i].setCharacterSize(18);
		Texts[i].setPosition(sf::Vector2f(RecShapes[i + 4].getPosition().x + 14, RecShapes[i + 4].getPosition().y));

		switch (i)
		{
		case 0:
			Texts[i].setString("Q");
			break;
		case 1:
			Texts[i].setString("W");
			break;
		case 2:
			Texts[i].setString("E");
			break;
		case 3:
			Texts[i].setString("R");
			break;
		default:
			break;
		}
	}

	//health text
	Texts[4].setFont(courier_font);
	Texts[4].setCharacterSize(16);
	Texts[4].setFillColor(sf::Color::Black);
	Texts[4].setPosition(sf::Vector2f(RecShapes[0].getPosition().x + RecShapes[0].getSize().x / 2 - 50, RecShapes[0].getPosition().y));
	Texts[4].setString("100 / 100");

	Texts.shrink_to_fit();
}

void GUI::draw()
{
	for (auto&& RecShape : RecShapes)
	{
		game.window.draw(RecShape);
	}
	
	for (auto&& Text : Texts)
	{
		game.window.draw(Text);
	}
}

bool GUI::update(float deltaTime) {	return false; }

void GUI::update_health(int health)
{
	RecShapes[0].setScale(health / float(100.0), 1);

	//std::string s;
	//std::stringstream (s) >> health;
	std::stringstream ss{ health };

	Texts[4].setString(ss.str() + " / 100");
}

void GUI::update_mana(int mana)
{
	RecShapes[2].setScale(mana / float(100.0), 1);
	
	std::stringstream ss{ mana };
	Texts[4].setString(ss.str() + " / 100");
}

void GUI::used_Q()
{
	//flash Q-box yellow
}

void GUI::used_W()
{

}

void GUI::used_E()
{

}

void GUI::used_R()
{

}

void GUI::upgraded_Q(int to_level) 
{
	switch (to_level)
	{
		case 1:
			RecShapes[8].setFillColor(sf::Color::Yellow);
			break;
		case 2:
			RecShapes[12].setFillColor(sf::Color::Yellow);
			break;
		default:
			break;
	}
}

void GUI::upgraded_W(int to_level)
{

}

void GUI::upgraded_E(int to_level)
{

}

void GUI::upgraded_R(int to_level)
{

}