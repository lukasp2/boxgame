#include "Hero_1.h"
#include <cmath>	// atan2
#include <iostream>

#define PI 3.14159265

Hero_1::Hero_1(Game& game) : Hero { game, sf::Color::Green, 20.0f, 3, "Rolf" }
{
	q.projectileShape.setFillColor	(sf::Color::Green);
	q.projectileShape.setSize		(sf::Vector2f(30.0f, 3.0f));
}

void Hero_1::Q()
{
	float delta_y = body.getPosition().y + window.getSize().y / 2 - sf::Mouse::getPosition(window).y;
	float delta_x = body.getPosition().x + window.getSize().x / 2 - sf::Mouse::getPosition(window).x;

	float radians = atan2(delta_y, delta_x);
	float degrees = static_cast<float>(180 / PI * radians);

	float x = -std::cos(radians);
	float y = -std::sin(radians);

	sf::Vector2f velocity { q.velocity * x, q.velocity * y };
	sf::Vector2f origin	{ body.getPosition().x + 2 * size * x, body.getPosition().y + 2 * size * y };

	//projectiles.push_back( Projectile { window, velocity, origin, q.projectileShape, degrees, q.damage, q.range} );
	Projectile p{ game, velocity, origin, q.projectileShape, degrees, q.damage, q.range };

	game.entities.push_back(std::make_unique<Projectile>(p));
}	

void Hero_1::W()
{
	float delta_y = body.getPosition().y + window.getSize().y / 2 - sf::Mouse::getPosition(window).y;
	float delta_x = body.getPosition().x + window.getSize().x / 2 - sf::Mouse::getPosition(window).x;

	float radians = atan2(delta_y, delta_x);
	float degrees = static_cast<float>(180 / PI * radians);

	float x = -std::cos(radians);
	float y = -std::sin(radians);

	body.setPosition( body.getPosition().x + w.flash_length * x, body.getPosition().y + w.flash_length * y );

	seekPosition = body.getPosition();
	startPosition = body.getPosition();

	x = 0;
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
