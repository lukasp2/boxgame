#include "Highscore.h"
#include "Main_Menu.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#define X_POS 100
#define Y_POS 0
#define CHAR_SIZE 35

Highscore::Highscore(State* previous_state) 
	: previous_state{previous_state}
{
	sf::Font& font{ Font_Manager::load("Fonts/courier.ttf") };
	header.setFont(font);
	header.setCharacterSize(CHAR_SIZE);
	header.setFillColor(sf::Color::Green);
	header.setPosition(sf::Vector2f(X_POS, Y_POS));
	header.setString("highscores");

	bottom = header;
	bottom.setString("... press enter to return");
	bottom.setPosition(X_POS, Y_POS + 50 + CHAR_SIZE * 11);

	std::ifstream inFile;
	inFile.open("highscore.txt");

	if (!inFile)
	{
		std::cerr << "unable to open highscore.txt";
		exit(1);
	}

	for (int i{}; i < 10; ++i)
	{
		sf::Text text;

		text.setFont(font);
		text.setCharacterSize(CHAR_SIZE);
		text.setFillColor(sf::Color::Green);
		text.setPosition( sf::Vector2f(X_POS, static_cast<float>(Y_POS + 50.0 + CHAR_SIZE * i)) );

		size_t score;
		inFile >> score;

		std::string str;
		std::getline(inFile, str);

		std::stringstream ss;
		ss << std::setw(2) << i + 1 << ". " << std::left << std::setw(20) << str << std::right << score;
		text.setString(ss.str());

		scoreVector.push_back(text);
	}

	inFile.close();
}

void Highscore::process_input()
{
	
}

State* Highscore::update()
{
	if (option.quit)
	{
		return previous_state.get();
	}

	return nullptr;
}

void Highscore::render(sf::RenderWindow & window)
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::KeyReleased:
		{
			switch (evnt.key.code)
			{
			case sf::Keyboard::Enter:
				option.quit = true;
				break;
			}
		}
		break;
		}
	}

	window.clear(sf::Color::Black);

	window.draw(header);
	window.draw(bottom);

	for (sf::Text text : scoreVector)
		window.draw(text);

	window.display();

	window.setView(menuView);
}
