#include "ClockHand.h"

#include "Cube.h"

ClockHand::ClockHand() {
	_angle=0;
}

void ClockHand::setAngle(float angle) {
    _angle = angle;
}

void ClockHand::draw() {
	Cube *cb = new Cube();
    
    cb -> draw();
}
float ClockHand::getAngle(){
	return _angle;
}

ClockHand::~ClockHand() {

}

