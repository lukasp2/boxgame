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
	struct q : public ability
	{
		q() : ability{ 5, 100, 0 }, velocity{ 800 }, damage{ 15 }, range{ 1000 }
		{
			projectileShape.setOutlineColor(sf::Color::Green);
			projectileShape.setFillColor(sf::Color::Black);
			projectileShape.setOutlineThickness(1.0f);
			projectileShape.setRadius(4.0f);
		}

		float velocity;
		size_t damage;
		size_t range;
		sf::CircleShape projectileShape;
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

