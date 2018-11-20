#pragma once
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Hero_1.h"

static const float VIEW_SIZE{ 900.0f };

class Game : public State
{
public:
	Game();

	virtual void process_input(sf::RenderWindow& window) override;
	virtual State* update(sf::RenderWindow& window) override;
	virtual void render(sf::RenderWindow& window) override;

private:
	sf::View view{ sf::Vector2f(0, 0), sf::Vector2f(VIEW_SIZE, VIEW_SIZE) };
	float aspectRatio;

	sf::Event evnt;
	sf::Clock clock;
	float deltaTime{ 0.0 };
	
	Hero_1 player{};

	struct Options
	{
		bool dead{ false };
		bool pause{ false };
		bool quit{ false };
	};
	Options option;

};


