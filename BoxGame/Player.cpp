#include "Player.h"

Player::Player()
{
	body.setSize(sf::Vector2f(100.0f,50.0f));
	body.setFillColor(sf::Color::Red);
}

void Player::update(float deltaTime)
{
	velocity.x *= 0.1f; //so the player doesn't
	velocity.y *= 0.1f; //accelerate away

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
		velocity.y -= speed;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
		velocity.x -= speed;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
		velocity.y += speed;
	
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
		velocity.x += speed;
	
	/*
	if (velocity.x > 0.0f)
		body.rotate(1.0f);
	
	else if (velocity.x < 0.0f) 
		row = 1;
	
	if (velocity.y < 0.0f) 
		row = 3;
	
	else if (velocity.y > 0.0f) 
		row = 0;

	if (velocity.y != 0.0f || velocity.x != 0.0f)
		animation.Update(row, deltaTime, true);

	body.setTextureRect(animation.uvRect);
	*/
	
	body.move(velocity * deltaTime);
}

void Player::draw(sf::RenderWindow & window)
{
	window.draw(body);
}

void Player::onCollision()
{
}

