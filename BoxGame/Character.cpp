#include "Character.h"

Character::Character(Game& game, float size, int speed, int health, std::string s_name, sf::Color color)
	: Entity{ game }, size{ size }, speed{ speed }, health{ health }, x{ 0 }, level{}
{
	// set character body
	body.setRadius(size);
	body.setFillColor(sf::Color::Transparent);
	body.setOutlineColor(color);
	body.setOutlineThickness(2.0f);
	body.setOrigin(body.getRadius(), body.getRadius());
	body.setPosition(0, 0);

	// set character name
	name.setFont(game.courier_font);
	name.setPosition(sf::Vector2f(-40, 300));
	name.setString(s_name);
}

void Character::move()
{
	float delta_x = abs(seekPosition.x - startPosition.x);
	float delta_y = abs(seekPosition.y - startPosition.y);

	float dist{ sqrt(delta_x * delta_x + delta_y * delta_y) };

	float n{ dist / speed};

	x++;
	
	float t = 1.0f;

	if (n > 0.001f)
		t = float(x) / n;
	
	sf::Vector2f v{ t * (seekPosition.x - startPosition.x), t * (seekPosition.y - startPosition.y) };
	
	if (x >= n)
		x = int(n);

	sf::Vector2f result = v + startPosition;

	body.setPosition(result);
}

void Character::draw()
{
	game.window.draw(body);
	draw_more();
}