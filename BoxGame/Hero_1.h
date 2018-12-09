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
	struct q : public shoot_ability
	{
		// shoot_ability{ mana cost, cooldown, velocity, damage, range }
		q() : shoot_ability{1, 100, 800, 15, 1000} 
		{
			projectileShape.setOutlineColor(sf::Color::Green);
			projectileShape.setFillColor(sf::Color::Black);
			projectileShape.setOutlineThickness(1.0f);
			projectileShape.setRadius(4.0f);
		}
	}; 
	q q{};

	struct w : public ability
	{
		w() : ability{15, 200}, flash_length{ 200 } {}
		int	flash_length{ };
	}; 
	
	w w{};

	struct e : public ability
	{
		e() : ability{ 15, 200 }, heal{ 200 } {}
		int	heal{ };
	}; 
	
	e e{};

	struct r : public ability
	{
		r() : ability{ 15, 200 }, damage{ 200 } {}
		int	damage{ };
	}; 
	
	r r{};
};

