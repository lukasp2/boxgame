#pragma once
#include "Hero.h"
#include "Game.h"

class Hero_1 : public Hero
{
public:
	Hero_1(Game& game);

	void Q() override;
	void W() override;
	void E() override;
	void R() override;

	void upgrade_Q() override;
	void upgrade_W() override;
	void upgrade_E() override;
	void upgrade_R() override;

private:
	mana_cost
		cooldown
		level
	struct q
	{
		q() : damage{ 15 }, range{ 1000 }, velocity{ 800 }, level{ 0 } {}
		int		level;
		float	velocity;
		size_t	damage;
		size_t	range;
		sf::CircleShape  projectileShape;
	}; q q{};

	struct w 
	{
		w() : level{ 0 }, flash_length{ 200 } {}
		int	level{ };
		int	flash_length{ };
	}; w w{};

	struct e 
	{
		e() : level{ 0 }, heal{ 200 } {}
		int	level{ };
		int	heal{ };
	}; e e{};

	struct r
	{
		r() : level{ 0 }, damage{ 200 } {}
		int	level{ };
		int	damage{ };
	}; r r{};
};

