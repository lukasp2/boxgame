#pragma once
#include "Hero.h"
#include "Game.h"
#include "Static_Projectile.h"

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
	struct q : public ability
	{
		q() : ability{ 5, 100, 0 }, static_proj{ 800, 35, 400, 4.0f, sf::Color::Green } {}
		Static_Projectile static_proj;
	};
	q q{};

	struct w : public ability
	{
		w() : ability{ 15, 200, 0 }, flash_length { 200 } {}
		int	flash_length{};
	}; 
	w w{};

	struct e : public ability
	{
		e() : ability{ 20, 200, 0 }, heal{ 200 } {}
		int	heal{ };
	}; 
	e e{};

	struct r : public ability
	{
		r() : ability{ 45, 200, 0 }, damage{ 200 } {}
		int	damage{ };
	}; 
	r r{};
};

