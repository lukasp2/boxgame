#pragma once
#include <SFML/Graphics.hpp>

#include "State.h"
class Hero;
class Entity;

static const float VIEW_SIZE{ 900.0f };

class Game : public State
{
public:
	Game(sf::RenderWindow& window);

	virtual void	process_input() override;
	virtual State*	update()		override;
	virtual void	render()		override;

	// should be private
	std::unique_ptr<Hero> player;
	std::vector< std::unique_ptr<Entity> > entities;

private:
	sf::View	view{ sf::Vector2f(0, 0), sf::Vector2f(VIEW_SIZE, VIEW_SIZE) };
	float		aspectRatio;

	sf::Event	evnt;
	sf::Clock	clock;
	float		deltaTime;
	
	struct Options
	{
		bool pause{ false };
		bool quit{ false };
	};
	Options option;
};