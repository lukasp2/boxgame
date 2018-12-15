#pragma once
#include "Entity.h"
#include "Character.h"

class Appearing_Character : public Entity
{
public:
	Appearing_Character(std::shared_ptr<Character> character);

	void draw()	override;
	bool update(float deltaTime) override;

private:
	std::shared_ptr<Character> character;
	float intended_radius;
};

