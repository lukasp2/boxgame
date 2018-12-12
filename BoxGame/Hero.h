#pragma once
#include <SFML\Graphics.hpp>

#include "Game.h"
#include "Character.h"
#include "Abilities.h"

class Hero : public Character
{
friend class GUI;
friend class Button;

public:
	Hero(Game& game, sf::Color color, float size, int speed, std::string name);
	~Hero() = default;

	bool	update(float deltaTime) override;
	void	proccess_input(sf::Event event);
	virtual void level_up();

	bool	changed_movement;

	bool	can_upgrade(int& level);
	int		upgrades_avalible{ 1 };

	//getters & setters
	double	getMana()			{ return mana;			}
	double	getXP()				{ return XP;			}
	int		getLevel()			{ return level;			}
	double	get_mana_reg()		{ return mana_regen;	}
	double	get_health_reg()	{ return health_regen;	}

protected:
	double	XP{ 0 };
	double	mana{ 100 };

	double mana_regen{};
	double health_regen{};

	int		level{ 1 };

	void draw_more() override;

	ability* q_ptr;
	ability* w_ptr;
	ability* e_ptr;
	ability* r_ptr;

	virtual void	Q() = 0;
	virtual void	W() = 0;
	virtual void	E() = 0;
	virtual void	R() = 0;

	virtual void	upgrade_Q() = 0;
	virtual void	upgrade_W() = 0;
	virtual void	upgrade_E() = 0;
	virtual void	upgrade_R() = 0;
};
