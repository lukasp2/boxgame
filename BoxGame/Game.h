#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "State.h"
#include "Clock.h"

class GUI;
class Hero;
class Entity;

static const float VIEW_SIZE{ 900.0f };

class Game : public State
{
public:
	Game(sf::RenderWindow& window);
	~Game();

	virtual void	process_input() override;
	virtual State*	update()		override;
	virtual void	render()		override;

	std::unique_ptr<GUI> user_interface;
	std::shared_ptr<Hero> player;
	std::vector< std::shared_ptr<Entity> > entities;

	Clock getClock() { return system_clock; }

private:
	sf::View	view{ sf::Vector2f(0, 0), sf::Vector2f(VIEW_SIZE, VIEW_SIZE) };
	float		aspectRatio;

	sf::Event	event;
	sf::Clock	frame_clock;
	Clock		system_clock;
	float		deltaTime;
	
	struct Options
	{
		bool pause{ false };
		bool quit{ false };
		bool gameover{ false };
	};
	Options option;
};