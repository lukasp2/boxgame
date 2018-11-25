#pragma once
#include "Hero.h"

class Hero_1 : public Hero
{
public:
	Hero_1(sf::RenderWindow& window);

	void Q() override;
	void W() override;
	void E() override;
	void R() override;

	void upgrade_Q() override;
	void upgrade_W() override;
	void upgrade_E() override;
	void upgrade_R() override;

private:
	struct q
	{
		q() : damage{ 40 }, range{ 1000 }, velocity{ 800 }, level{ 0 } {}
		int		level;
		float	velocity;
		size_t	damage;
		size_t	range;
		sf::RectangleShape  projectileShape;
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

