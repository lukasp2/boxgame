#include "Hero_1.h"
#include "Projectile.h"
#include "Disappearing_Character.h"
#include <cmath>	// atan2
#include <iostream>

#define PI 3.14159265

Hero_1::Hero_1(Game& game) : Hero { game, sf::Color::Green, 20.0f, 3, "Rolf" }
{
	q.projectileShape.setOutlineColor		(sf::Color::Green);
	q.projectileShape.setFillColor			(sf::Color::Black);
	q.projectileShape.setOutlineThickness	(1.0f);
	q.projectileShape.setRadius				(4.0f);
}

void Hero_1::Q()
{
	float delta_y = body.getPosition().y + game.window.getSize().y / 2 - sf::Mouse::getPosition(game.window).y;
	float delta_x = body.getPosition().x + game.window.getSize().x / 2 - sf::Mouse::getPosition(game.window).x;

	float radians = atan2(delta_y, delta_x);
	float degrees = static_cast<float>(180 / PI * radians);

	float x = -std::cos(radians);
	float y = -std::sin(radians);

	sf::Vector2f velocity { q.velocity * x, q.velocity * y };
	sf::Vector2f origin	{ body.getPosition().x + 2 * size * x, body.getPosition().y + 2 * size * y };

	Projectile p{ game, velocity, origin, q.projectileShape, degrees, q.damage, q.range };

	game.entities.push_back(std::make_unique<Projectile>(p));
}	

void Hero_1::W()
{
	float delta_x = body.getPosition().x + game.window.getSize().x / 2 - sf::Mouse::getPosition(game.window).x;
	float delta_y = body.getPosition().y + game.window.getSize().y / 2 - sf::Mouse::getPosition(game.window).y;

	float radians = atan2(delta_y, delta_x);
	float degrees = static_cast<float>(180 / PI * radians);

	float x = -std::cos(radians);
	float y = -std::sin(radians);
	
	// creating the fading circle on the point we jumped from
	game.entities.push_back(std::make_shared<Disappearing_Character>(game, body, sf::Color::Yellow, 30));
	
	// determining whether to jump max flash length or to cursor
	float a_length	{ sqrt(delta_x * delta_x + delta_y * delta_y) };
	int b_length	{ w.flash_length };

	if (a_length > b_length)
		body.setPosition(body.getPosition().x + w.flash_length * x, body.getPosition().y + w.flash_length * y);
	else
		body.setPosition(sf::Mouse::getPosition(game.window).x - static_cast<float>(game.window.getSize().x / 2), sf::Mouse::getPosition(game.window).y - static_cast<float>(game.window.getSize().y / 2));

	seekPosition = body.getPosition();
	startPosition = body.getPosition();

	x = 0;

	// for the enemy to know we have changed location not based on mouse input
	changed_movement = true;
}

void Hero_1::E()
{

}

void Hero_1::R()
{

}

void Hero_1::upgrade_Q()
{
	//q.damage = 60 80 140 220 
	q.level++;
	q.damage += 20 * q.level;
}

void Hero_1::upgrade_W()
{
	//w.jump = 
	w.level++;
	w.flash_length += 20 * w.level;
}

void Hero_1::upgrade_E()
{
	//e.heal =
	e.level++;
	e.heal += 20 * e.level;
}

void Hero_1::upgrade_R()
{
	//r.damage = 
	r.level++;
	r.damage += 20 * r.level;
}

//void Hero_1::draw() {}
