#pragma once
#include "Bar.h"
class XPbar : public Bar
{
public:
	using Bar::Bar;
	
	bool update() override;
};

