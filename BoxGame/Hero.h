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

	bool update(float deltaTime) override;
	void process_input(sf::Event::KeyEvent event);

	bool changed_movement;

	int upgrades_avalible{ 20 };

	float mana{ 100 };

protected:
	void draw_more() override;
	/*
	struct base_q : public ability { using ability::ability; };
	base_q b_q;

	struct base_w : public ability { using ability::ability; };
	base_w b_w;

	struct base_e : public ability { using ability::ability; };
	base_e b_e;

	struct base_r : public ability { using ability::ability; };
	base_r b_r;
	*/
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
