#include "Hero_1.h"
#include "Projectile.h"
#include "Disappearing_Character.h"
#include <cmath>	// atan2
#include "GUI.h"	// user_interface upgrades

#define PI 3.14159265

Hero_1::Hero_1(Game& game) : Hero { game, sf::Color::Green, 20.0f, 1.0f, "Rolf" }
{
	Hero::q_ptr = &q;
	Hero::w_ptr = &w;
	Hero::e_ptr = &e;
	Hero::r_ptr = &r;
}

void Hero_1::Q()
{
	if (mana >= q.mana_cost && q.level > 0 && q.clock.getElapsedTime().asSeconds() > q.cooldown)
	{
		float delta_y = body.getPosition().y + game.window.getSize().y / 2 - sf::Mouse::getPosition(game.window).y;
		float delta_x = body.getPosition().x + game.window.getSize().x / 2 - sf::Mouse::getPosition(game.window).x;

		float radians = atan2(delta_y, delta_x);
		float degrees = static_cast<float>(180 / PI * radians);

		float x = -std::cos(radians);
		float y = -std::sin(radians);

		sf::Vector2f velocity { q.static_proj.getVelocity() * x, q.static_proj.getVelocity() * y };
		sf::Vector2f origin	{ body.getPosition().x + 2 * size * x, body.getPosition().y + 2 * size * y };

		Projectile p{ game, q.static_proj, velocity, origin, Projectile::type::friendly };

		game.add(std::make_unique<Projectile>(p));

		q.clock.restart();
		mana -= q.mana_cost;
	}
}

void Hero_1::W()
{
	if (mana >= w.mana_cost && w.level > 0 && w.clock.getElapsedTime().asSeconds() > w.cooldown)
	{
		changed_movement = false;

		float delta_x = body.getPosition().x + game.window.getSize().x / 2 - sf::Mouse::getPosition(game.window).x;
		float delta_y = body.getPosition().y + game.window.getSize().y / 2 - sf::Mouse::getPosition(game.window).y;

		float radians = atan2(delta_y, delta_x);
		float degrees = static_cast<float>(180 / PI * radians);

		float x = -std::cos(radians);
		float y = -std::sin(radians);
	
		// creating the fading circle on the point we jumped from
		game.add(std::make_shared<Disappearing_Character>(game, body, sf::Color::Yellow, 30));
	
		// determining whether to jump max flash length or to cursor
		float a_length	{ sqrt(delta_x * delta_x + delta_y * delta_y) };
		int b_length	{ w.flash_length };

		if (a_length > b_length)
		{
			body.setPosition(body.getPosition().x + w.flash_length * x, body.getPosition().y + w.flash_length * y);
		}
		else
		{
			body.setPosition(sf::Mouse::getPosition(game.window).x - static_cast<float>(game.window.getSize().x / 2), sf::Mouse::getPosition(game.window).y - static_cast<float>(game.window.getSize().y / 2));
		}

		setInnerBodyPos();

		seekPosition = body.getPosition();
		startPosition = body.getPosition();

		x = 0;

		// for the enemy to know we have changed location not based on mouse input
		changed_movement = true;

		w.clock.restart();
		mana -= w.mana_cost;
	}
}

void Hero_1::E()
{
	if (mana >= e.mana_cost && e.level > 0)
	{

		mana -= e.mana_cost;
	}
}

void Hero_1::R()
{
	if (mana >= r.mana_cost && r.level > 0)
	{

		mana -= r.mana_cost;
	}
}

void Hero_1::upgrade_Q()
{
	if (can_upgrade(q.level))
	{
		q.mana_cost += 2;
		w.cooldown *= 0.8f;
		q.static_proj.setDamage(20 * q.level);
	}
}

void Hero_1::upgrade_W()
{
	//w.jump = 
	if (can_upgrade(w.level))
	{
		w.mana_cost += 4;
		w.cooldown *= 0.8f;
		w.flash_length += 20 * w.level;
	}
}

void Hero_1::upgrade_E()
{
	//e.heal =
	if (can_upgrade(e.level))
	{
		e.mana_cost += 5;
		e.heal += 20 * e.level;
	}
}

void Hero_1::upgrade_R()
{
	//r.damage = 
	if (can_upgrade(r.level))
	{
		r.mana_cost += 10;
		r.damage += 20 * r.level;
	}
}

//void Hero_1::draw() {}
