#include "Hero_1.h"
#include <iostream>	// debugging
#include <cmath>	// atan2

#define PI 3.14159265

Hero_1::Hero_1(sf::RenderWindow& window_) : Hero{ window_, sf::Color::Red, 20, 800, getName() }
{
	q.projectileShape.setFillColor(sf::Color::Magenta);
	q.projectileShape.setSize(sf::Vector2f(40.0f, 10.0f));
}

void Hero_1::Q()
{
	//sf::RenderWindow* win = &window_;
	float delta_y = body.getPosition().y + window_.getSize().y / 2 - sf::Mouse::getPosition(window_).y;
	float delta_x = body.getPosition().x + window_.getSize().x / 2 - sf::Mouse::getPosition(window_).x;

	float radians = atan2( delta_y, delta_x );
	float degrees = static_cast<float>(180 / PI * radians) - 180;
	
	float damage = 10.0;
	sf::Vector2f vel{ float(5.0) * delta_x, float(5.0) * delta_y };

	q.projectiles.push_back( Projectile{ q.projectileShape, damage, vel, -degrees, body.getPosition() });
}

void Hero_1::W()
{
	sf::Mouse::getPosition(window_);
	//body.setPosition

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
	std::cout << "hero_1 upgraded Q" << std::endl;
	q.level++;
	q.damage += 20 * q.level;
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

void Hero_1::draw()
{
	window_.draw(body);

	for (Projectile& p : q.projectiles)
		p.draw(window_);

	window_.draw(hero_name);
}

void Hero_1::update_more(float deltaTime)
{
	for (auto pit = q.projectiles.begin(); pit != q.projectiles.end(); )
	{
		//Projectile is updated and erased after some time
		if (pit->update(deltaTime, q.range))
			pit = q.projectiles.erase(pit);
		else
			pit++;
	}

}
