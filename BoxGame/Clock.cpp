#include "Clock.h"
#include <sstream>
#include <iomanip>

Clock::Clock() : clock{}
{
	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };

	text_clock.setFont(courier_font);
	text_clock.setCharacterSize(16);
	text_clock.setFillColor(sf::Color::White);
	text_clock.setPosition(sf::Vector2f(340, -410));
}

sf::Text Clock::get_as_text()
{
	int total_seconds = static_cast<int>(clock.getElapsedTime().asSeconds());

	int seconds = total_seconds % 60;
	int minutes = ((total_seconds - seconds) / 60) % 60;
	int hours = (((total_seconds - seconds - minutes * 60) / 3600) % 60) % 24;

	std::stringstream ss;

	ss << std::setfill('0');

	if (hours != 0)
	{
		ss << std::setw(2) << std::to_string(hours) << ":";
	}
	
	ss << std::setw(2) << std::to_string(minutes) << ":" << std::setw(2) << std::to_string(seconds);

	text_clock.setString(ss.str());

	return text_clock;
}
