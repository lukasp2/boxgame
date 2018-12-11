#pragma once
#include "Bar.h"
class Manabar : public Bar
{
public:
	using Bar::Bar;

	bool update() override;
};

