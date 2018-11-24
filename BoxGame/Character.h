#pragma once
#include "Drawable.h"
class Character : public Drawable
{
public:
	Character(sf::RenderWindow& window, float size, int speed, int health, std::string name, sf::Color color);

	virtual void	update(float deltaTime) {};
	virtual void	draw() = 0;

	void			onCollision() {}

	bool			death_check() { return health <= 0;			}
	sf::Vector2f	getPosition() { return body.getPosition();	}
	void			update();
	void			move_to(sf::Vector2f& go_Here);

protected:
	sf::Vector2f	velocity;

	sf::CircleShape body;
	float			size;
	int				health;
	int				speed;
	int				level;
	int				XP;
	sf::Text		name;

	sf::Vector2f startPosition;
	sf::Vector2f seekPosition;

private:
	sf::Font& courier_font{ Font_Manager::load("Fonts/courier.ttf") };
};

