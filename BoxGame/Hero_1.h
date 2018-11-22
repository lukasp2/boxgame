#pragma once
#include "Hero.h"

class Hero_1 : public Hero
{
public:
	Hero_1(sf::RenderWindow& window_);

	void draw() override;
	void update_more(float deltaTime) override;

	void Q() override;
	void W() override;
	void E() override;
	void R() override;

	void upgrade_Q() override;
	void upgrade_W() override;
	void upgrade_E() override;
	void upgrade_R() override;

	std::string getName() override { return "Sagga"; }
	//int getRange() { return q.range; }

private:
	/////PLAYER STATS////
	sf::Color color { sf::Color::Red };
	int health{ 100 };
	int speed{ 800 };
	int size{ 20 };
	/////////////////////
	
	///////// Q /////////
	struct q
	{
		q() : level{ 0 }, damage{ 40 }, velocity{ 10 }, range{ 2000 } {}
		int level{ };
		size_t damage{ };
		float velocity{ };
		int range{ };	

		sf::RectangleShape projectileShape;
		std::vector<Projectile> projectiles;
	}; q q;
	/////////////////////

	///////// W /////////
	struct w
	{
		w() : level{ 0 }, flash_length{ 200 } {}
		int level{ };
		int flash_length{ };
	}; w w;
	/////////////////////

	///////// E /////////
	struct e
	{
		e() : level{ 0 }, heal{ 200 } {}
		int level{ };
		int heal{ };
	}; e e;
	/////////////////////

	///////// R /////////
	struct r
	{
		r() : level{ 0 }, damage{ 200 } {}
		int level{ };
		int damage{ };
	}; r r;
	/////////////////////
};

