#include "ClockHand.h"

#include "Cube.h"

ClockHand::ClockHand() {
	_angle=0;
	float ambC[3] = {0.2, 0.2, 0.2};
	float difC[3] = {0.6, 0.6, 0.6};
	float specC[3] = /* {0.2, 0.2, 0.2} */ {0.0, 0.2, 0.8};
	float shininessC = /*   10.f    */ 120.0f;
	
	chAppearance = new CGFappearance(ambC, difC, specC, shininessC);
}

void ClockHand::setAngle(float angle) {
    _angle = angle;
	
}

void ClockHand::draw() {
	Cube chand;
	glPushMatrix();
		glScaled(0.2,1,0.2);
	glPopMatrix();
	
	switch (_tt) {
	case kTimeTypeSeconds:
		glPushMatrix();
			glRotated(_angle,1,0,0);
			glScaled(0.025,0.42,0.05);
			glTranslated(2.4,0,0);
			chAppearance->apply();
			chand.draw();
		glPopMatrix();
		break;

	case kTimeTypeMinutes:
		glPushMatrix();
			glRotated(_angle,1,0,0);
			glScaled(0.025,0.6,0.05);
			glTranslated(2.2,0,0);
			chAppearance->apply();
			chand.draw();
		glPopMatrix();
		break;

	case kTimeTypeHours:
		glPushMatrix();
			glRotated(_angle,1,0,0);
			glScaled(0.025,0.69,0.01);
			glTranslated(2.8,0,0);
			chAppearance->apply();
			chand.draw();
		glPopMatrix();
		break;
	}
}

float ClockHand::getAngle(){
	return _angle;
}

ClockHand::~ClockHand() {

}

