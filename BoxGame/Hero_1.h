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
	struct q
	{
		// shoot_ability{ mana cost, cooldown, velocity, damage, range }
		q() : a{1, 100}, velocity { 800 }, damage{ 15 }, range{ 1000 }
		{
			projectileShape.setOutlineColor(sf::Color::Green);
			projectileShape.setFillColor(sf::Color::Black);
			projectileShape.setOutlineThickness(1.0f);
			projectileShape.setRadius(4.0f);
		}

		ability a;
		float velocity;
		size_t damage;
		size_t range;
		sf::CircleShape projectileShape;
	};
	q q{};

	struct w
	{
		w() : a{15, 200}, flash_length{ 200 } {}
		ability a;
		int	flash_length{ };
	}; 
	
	w w{};

	struct e
	{
		e() : a{ 15, 200 }, heal{ 200 } {}
		ability a;
		int	heal{ };
	}; 
	
	e e{};

	struct r
	{
		r() : a{ 15, 200 }, damage{ 200 } {}
		ability a;
		int	damage{ };
	}; 
	
	r r{};
};

