#include "Highscore.h"
#include "Main_Menu.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#define X_POS 100		//X & Y placement of text
#define Y_POS 0			
#define CHAR_SIZE 35	//text size
#define NUM_SCORES 10	//numeber of highscores to be displayed

Highscore::Highscore(sf::RenderWindow& window) : State{ window }
{
	header.setFont(courier_font);
	header.setCharacterSize(CHAR_SIZE);
	header.setFillColor(sf::Color::Green);
	header.setPosition(sf::Vector2f(X_POS, Y_POS));
	header.setString("highscores");

	bottom = header;
	bottom.setString("press enter to return...");
	bottom.setPosition(X_POS, Y_POS + CHAR_SIZE * (NUM_SCORES + 2));

	std::ifstream inFile;
	inFile.open("highscore.txt");

	if (!inFile)
	{
		std::cerr << "unable to open highscore.txt";
		exit(1);
	}

	std::vector< std::pair<std::string, int> > v;

	int score;
	while (inFile >> score)
	{
		std::string str;
		std::getline(inFile, str);

		v.push_back(std::make_pair(str, score));
	}
	std::sort(v.begin(), v.end(), [](auto a, auto b) { return a.second > b.second; });

	sf::Text text;
	text.setFont(courier_font);
	text.setCharacterSize(CHAR_SIZE);
	text.setFillColor(sf::Color::Green);

	for (size_t i{}; i < NUM_SCORES && i < v.size(); ++i)
	{
		std::stringstream ss;
		ss << std::setw(2) << i + 1 << "." << std::left << std::setw(20) << std::setfill('.') << v[i].first << std::right << v[i].second;
		text.setString(ss.str());
		text.setPosition( sf::Vector2f(X_POS, static_cast<float>(Y_POS + CHAR_SIZE * (i + 1))) );

		scoreVector.push_back(text);
	}

	inFile.close();
}

void Highscore::process_input()
{
	while (window.pollEvent(evnt))
	{
		switch (evnt.type)
		{
		case sf::Event::KeyPressed:
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
}

State* Highscore::update()
{
	if (option.quit)
	{
		option.quit = false;
		state_ptr = std::make_unique<Main_Menu>(window);
		return state_ptr.get();
	}

	return nullptr;
}

void Highscore::render()
{
	window.clear(sf::Color::Black);

	window.draw(header);
	window.draw(bottom);

	for (sf::Text text : scoreVector)
		window.draw(text);

	window.display();

	window.setView(menuView);
}
