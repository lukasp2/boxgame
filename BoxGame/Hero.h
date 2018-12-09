#pragma once
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Character.h"

class Hero : public Character
{
public:
	~Hero() = default;
	Hero(Game& game, sf::Color color, float size, int speed, std::string name);

	bool update(float deltaTime) override;
	void process_input(sf::Event::KeyEvent event);

	bool changed_movement;

protected:
	float mana{ 100 };
	size_t upgrades_avalible{ 1 };

	void draw_more() override;

	virtual void	Q() = 0;
	virtual void	W() = 0;
	virtual void	E() = 0;
	virtual void	R() = 0;

	virtual void	upgrade_Q() = 0;
	virtual void	upgrade_W() = 0;
	virtual void	upgrade_E() = 0;
	virtual void	upgrade_R() = 0;
};