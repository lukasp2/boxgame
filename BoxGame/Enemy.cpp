#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& window, sf::Color color, float size, int speed, int health, size_t damage, std::string name)
	: Character{ window, size, speed, health, name, color }
{}