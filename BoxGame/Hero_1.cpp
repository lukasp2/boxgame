#include "Hero_1.h"
#include <iostream>

Hero_1::Hero_1() : Hero{ sf::Color::Red, 20, 800 } 
{
	projectile.setFillColor(sf::Color::Magenta);
	projectile.setSize(sf::Vector2f(40.0f, 10.0f));
}

void Hero_1::Q()
{
	std::cout << "hero_1 used Q" << std::endl;

	float angle = ((body.getPosition().x - sf::Mouse::getPosition().x) / (body.getPosition().y - sf::Mouse::getPosition().y));
	float damage = 10.0;
	sf::Vector2f vel{ 200.0, 10.0 };

	playerProjectiles.push_back( Projectile{ projectile, damage, vel, angle, body.getPosition() });
}

void Hero_1::W()
{

}

void Hero_1::E()
{

}

void Hero_1::R()
{

}

void Hero_1::upgrade_Q()
{
	std::cout << "hero_1 upgraded Q" << std::endl;
}

void Hero_1::upgrade_W()
{

}

void Hero_1::upgrade_E()
{

}

void Hero_1::upgrade_R()
{
}
