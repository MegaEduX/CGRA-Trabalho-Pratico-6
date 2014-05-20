#include "Robot.h"


Robot::Robot(int stacks) {

	// ambC[3] = {0.2, 0.2, 0.2};
	//float difC[3] = {0.6, 0.6, 0.6};
	//float specC[3] = /* {0.2, 0.2, 0.2} */ {0.0, 0.2, 0.8};
	//float shininessC = /*   10.f    */ 120.0f;
	
	//rAppearance = new CGFappearance(ambC, difC, specC, shininessC);
	_xpos = 7;
	_ypos = 4;
	_zpos = 7;
	_angle= 90;
	_stacks = stacks;
	_slices = 12;

}

void Robot::setAngle(float angle){
	_angle = angle;
}

void Robot::setPosition(float xpos, float ypos, float zpos){
	_xpos=xpos;
	_ypos=ypos;
	_zpos=zpos;
}


void Robot::draw() {
		const double PI  =3.141592653589793238463;
		double dx = 1/3 , alpha = -5 * PI / 4 , dalpha = -PI / 6 ;

	//TOP
		glPushMatrix();
		glNormal3d(0,1,0);
			glBegin(GL_POLYGON);

				for (int i = 0; i < 12; i++) {
					double x1 = cos((alpha + dalpha * (i))) * 0.25;
					double z1 = sin((alpha + dalpha * (i))) * 0.25;
					double x2 = cos((alpha + dalpha * (i + 1))) * 0.25;
					double z2 = sin((alpha + dalpha * (i + 1))) * 0.25;

					glNormal3d(0,1,0);
					glVertex3f(x1, 1, z1);
					glNormal3d(0,1,0);
					glVertex3f(x2, 1, z2);
				}

			glEnd();
	// Sides

	glTranslated(_xpos, _ypos, _zpos);
	glRotated(_angle,0,1,0);
	for (int j = 0; j < 4; j++) {

		glRotated(90 * j, 0, 1, 0);
		for (int i = 0; i < 3; i++) {
			double x1 = cos((alpha + dalpha * (i))) * 0.25;
			double z1 = sin((alpha + dalpha * (i))) * 0.25;
			double x2 = cos((alpha + dalpha * (i + 1))) * 0.25;
			double z2 = sin((alpha + dalpha * (i + 1))) * 0.25;
			double px1 = -0.5 + (1 / 3.0) * i;
			double px2 = -0.5 + (1 / 3.0) * (i + 1);
			double pz1 = 0.5, pz2 = 0.5;
			double py = 0;
			double dex1 = abs((x1 - px1) / _stacks), dey = abs(
					(1 - py) / _stacks), dez1 = abs((z1 - pz1) / _stacks);
			double dex2 = abs((x2 - px2) / _stacks), dez2 = abs(
					(z2 - pz2) / _stacks);
			glBegin(GL_TRIANGLE_STRIP);
			glNormal3d(px1, 0, pz1);
			glVertex3f(px1, py, pz1);
			glNormal3d(px2, 0, pz2);
			glVertex3f(px2, py, pz2);
			for (int k = 1; k < _stacks; k++) {
				if (px1 < 0)
					px1 = px1 + dex1;
				else
					px1 = px1 - dex1;
				if (px2 < 0)
					px2 = px2 + dex2;
				else
					px2 = px2 - dex2;
				py = py + dey;
				pz1 = pz1 - dez1;
				pz2 = pz2 - dez2;

				glNormal3d(px1, 0, pz1);
				glVertex3f(px1, py, pz1);
				glNormal3d(px2, 0, pz2);
				glVertex3f(px2, py, pz2);

			}

			glNormal3d(x1, 0, z1);
			glVertex3f(x1, 1, z1);
			glNormal3d(x2, 0, z2);
			glVertex3f(x2, 1, z2);
			glEnd();
		}
	}
	glPopMatrix();

}





