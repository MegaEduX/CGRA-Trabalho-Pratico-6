#pragma once
#include "Cylinder.h"
#include "ClockHand.h"
class Clock
{
	 Cylinder* clockCyl;


public:
	ClockHand* HourHand;
	ClockHand* MinHand;
	ClockHand* SecHand;
	Clock(void);
	void draw();
	~Clock(void);
};
