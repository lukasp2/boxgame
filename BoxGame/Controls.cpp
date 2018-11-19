#include "Controls.h"
#include "Main_Menu.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>

#define X_POS 100
#define Y_POS 0
#define CHAR_SIZE 35

Controls::Controls(State* previous_state)
	: previous_state{ previous_state }
{
	sf::Font& font{ Font_Manager::load("Fonts/courier.ttf") };
	header.setFont(font);
	header.setCharacterSize(CHAR_SIZE);
	header.setFillColor(sf::Color::Green);
	header.setPosition(sf::Vector2f(X_POS, Y_POS));
	header.setString("controls");

	std::ifstream inFile;
	inFile.open("controls.txt");

	if (!inFile)
	{
		std::cerr << "unable to open controls.txt";
		exit(1);
	}

	std::string s;
	int i{ 0 };
	while (1)
	{
		sf::Text text;
		std::stringstream ss;

		std::getline(inFile, s, ':');
		
		if (s == "--") 
			break;
		
		ss << std::left << std::setw(20) << s;

		std::getline(inFile, s);
		ss << s;
	
		text.setString(ss.str());
		text.setFont(font);
		text.setCharacterSize(CHAR_SIZE);
		text.setFillColor(sf::Color::Green);
		text.setPosition(sf::Vector2f(X_POS, static_cast<float>(Y_POS + CHAR_SIZE * ++i)));

		controlVector.push_back(text);
	}

	bottom = header;
	bottom.setString("... press enter to return");
	bottom.setPosition(X_POS, Y_POS + CHAR_SIZE * ++(++i));

	inFile.close();
}

void Controls::process_input()
{
}

State * Controls::update()
{
	if (option.quit)
	{
		return previous_state.get();
	}

	return nullptr;
}

void Controls::render(sf::RenderWindow & window)
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

	for (sf::Text text : controlVector)
		window.draw(text);

	window.display();

	window.setView(menuView);
}
