#pragma once
#include <SFML/Graphics.hpp>

#include "State.h"
#include "Player.h"

class Game : public State
{
public:
	Game();

	virtual void process_input() override;
	virtual State* update() override;
	virtual void render(sf::RenderWindow& window) override;

private:
	const float VIEW_SIZE{ 3000.0f };
	sf::View view{ sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_SIZE, VIEW_SIZE) };
	sf::Event evnt;
	sf::Clock clock;
	float deltaTime{ 0.0 };
	
	Player player;

	struct Options
	{
		bool dead{ false };
		bool pause{ false };
		bool quit{ false };
	};
	Options option;

};


