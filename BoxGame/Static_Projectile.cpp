#include "Static_Projectile.h"

Static_Projectile::Static_Projectile(float velocity, size_t damage, size_t range, float radius, sf::Color color)
	: velocity{ velocity }, damage{ damage }, range{ range }
{
	shape.setRadius(radius);
	shape.setOutlineColor(color);
	shape.setFillColor(sf::Color::Black);
	shape.setOutlineThickness(1.0f);
	shape.setOrigin(radius, radius);
	shape.setFillColor(sf::Color::Transparent);
}
