#pragma once
#include "Timed_Text.h"
class Fading_Text : public Timed_Text
{
public:
	Fading_Text(Game& game, std::string txt, sf::Color color, sf::Vector2f position, size_t size, float total_life_length, float start_fade_at, float show_text_at, int dissappear_speed = 1, int appear_speed = 255)
		: Timed_Text{ game, txt, color, position, size, total_life_length }, 
		total_life_length{ total_life_length }, 
		show_text_at{ show_text_at }, 
		dissappear_speed{ dissappear_speed }, 
		appear_speed{appear_speed} 
	{}

	virtual bool update() override;
	void draw() override;

protected:
	sf::Clock clock;
	bool show_text{ false };

	int dissappear_speed;
	int appear_speed;
	float total_life_length;
	float show_text_at;
};

