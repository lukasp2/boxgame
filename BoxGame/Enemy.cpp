#include "Enemy.h"

Enemy::Enemy(sf::RenderWindow& window, sf::Color color, float size, int speed, int health, size_t damage, std::string name)
	: Character{ window, size, speed, health, name, color }
{

}

void Enemy::update(float deltaTime, sf::Vector2f playerPos)
{
	seekPosition = playerPos;

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
	{
		startPosition = sf::Vector2f{ body.getPosition().x, body.getPosition().y };
	}

	Character::calculateOptimalMovement();

	//update_more(playerPos)?

	body.move(velocity * deltaTime);
}