#pragma once
#include "Text.h"
#include "Enemy.h"

class Enemy_Name : public Text
{
public:
	Enemy_Name(Game& game, Character& enemy);

	bool update() override;
	void draw() override;

private:
	Character& enemy;
};

