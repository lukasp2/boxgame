#pragma once
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Hero_1.h"

static const float VIEW_SIZE{ 900.0f };

class Game : public State
{
public:
	Game(sf::RenderWindow& window);

	virtual void process_input() override;
	virtual State* update() override;
	virtual void render() override;

private:
	sf::View view{ sf::Vector2f(0, 0), sf::Vector2f(VIEW_SIZE, VIEW_SIZE) };
	float aspectRatio;

	sf::Event evnt;
	sf::Clock clock;
	float deltaTime{ 0.0 };
	
	Hero_1 player{window};

	struct Options
	{
		bool dead{ false };
		bool pause{ false };
		bool quit{ false };
	};
	Options option;

};


