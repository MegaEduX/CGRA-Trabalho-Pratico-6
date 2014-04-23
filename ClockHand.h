#pragma once

#include "CGFobject.h"

class ClockHand {
    
    float _angle;

	bool _skipDrawing;
    
public:
    
	ClockHand();
    
    void setAngle(float angle);

	float getAngle();
    
	void draw();
    
	~ClockHand();
};
