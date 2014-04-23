#include "Clock.h"

#include "CGFappearance.h"

Clock::Clock() {
	clockCyl = new Cylinder(12, 1, true);
    clockCyl->setIsClock(true);
	HourHand = new ClockHand();
	MinHand = new ClockHand();
	SecHand = new ClockHand();
}

void Clock::draw() {
	glPushMatrix();
    
    glRotated(90, 1, 0, 0);
    
    clockCyl->draw();
    
    glPopMatrix();
}

Clock::~Clock() {
    
}