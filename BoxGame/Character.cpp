#include "Character.h"

Character::Character(Game& game, float size, int speed, double health, std::string s_name, sf::Color color)
	: Entity{ game }, size{ size }, speed{ speed }, health{ health }, x{ 0 }, level{}
{
	// set character body
	body.setRadius(size);
	body.setFillColor(sf::Color::Transparent);
	body.setOutlineColor(color + sf::Color(50,50,50));
	body.setOutlineThickness(2.0f);
	body.setOrigin(body.getRadius(), body.getRadius());
	body.setPosition(0, 0);

	inner_body = body;
	inner_body.setRadius(size - 3);
	inner_body.setOutlineThickness(8.0f);
	inner_body.setOutlineColor(color - sf::Color(0,0,0,190));

	// set character name
	name.setFont(game.courier_font);
	name.setPosition(sf::Vector2f(-40, 300));
	name.setString(s_name);
}

void Character::move()
{
	float delta_x = abs(seekPosition.x - startPosition.x);
	float delta_y = abs(seekPosition.y - startPosition.y);

	if (delta_x > 5 || delta_y > 5) 
	{
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
		inner_body.setPosition(result.x + 3, result.y + 3);
	}
}

void Character::draw()
{
	game.window.draw(body);
	game.window.draw(inner_body);
	draw_more();
}