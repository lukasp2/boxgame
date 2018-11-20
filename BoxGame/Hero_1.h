#pragma once
#include "Hero.h"

class Hero_1 : public Hero
{
public:
	Hero_1() : Hero{ sf::Color::Red, 20, 800 } {}

	void Q() override;
	void W() override;
	void E() override;
	void R() override;

	void upgrade_Q() override;
	void upgrade_W() override;
	void upgrade_E() override;
	void upgrade_R() override;

	std::string getName() override { return "Sagga"; }

private:	
	sf::Color color { sf::Color::Red };
	int health{ 100 };
	int speed{ 800 };
	int size{ 20 };

	int XP{ 0 };
};

