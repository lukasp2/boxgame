#pragma once
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Character.h"

class Hero : public Character
{
public:
	~Hero() = default;
	Hero(Game& game, sf::Color color, float size, int speed, std::string name);

	void update(float deltaTime) override;

	// abilities
	virtual void	Q() = 0;
	virtual void	W() = 0;
	virtual void	E() = 0;
	virtual void	R() = 0;

	// upgrades
	virtual void	upgrade_Q() = 0;
	virtual void	upgrade_W() = 0;
	virtual void	upgrade_E() = 0;
	virtual void	upgrade_R() = 0;
};