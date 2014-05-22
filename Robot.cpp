#include "Robot.h"
#define PI 3.141592653589793238463
#define DegToRad PI/180
#include <cmath>


Robot::Robot(double xpos, double ypos , double zpos,double yOrient, int stacks) {

	// ambC[3] = {0.2, 0.2, 0.2};
	//float difC[3] = {0.6, 0.6, 0.6};
	//float specC[3] = /* {0.2, 0.2, 0.2} */ {0.0, 0.2, 0.8};
	//float shininessC = /*   10.f    */ 120.0f;
	
	//rAppearance = new CGFappearance(ambC, difC, specC, shininessC);
	_xpos = xpos;
	_ypos = ypos;
	_zpos = zpos;
	_angle= yOrient;
	_stacks = stacks;
	_textured = true;

	float xInit =-0.5 , zInit=0.5 , jump=0;
	int orient=1;

	//CIRCLE -> POINTS AND NORMALS
	for (int i=0; i<13; i++){
		_xPositionsCircle.push_back(sin((315+jump)*DegToRad)/4.0);
		_zPositionsCircle.push_back(cos((315+jump)*DegToRad)/4.0);
		_zPositionsTop.push_back(cos((315+jump-100)*DegToRad)/4.0);
		_xPositionsTop.push_back(sin((315+jump-100)*DegToRad)/4.0);
		_yPositionsTop.push_back(-0.5);
		if( (i==3) || (i==6) || (i=9)){
			_xPositionsCircle.push_back(sin((315+jump)*DegToRad) / 4.0);
			_zPositionsCircle.push_back(cos((315+jump)*DegToRad)/4.0);
			_zPositionsTop.push_back(cos((315+jump-100)*DegToRad)/4.0);
			_xPositionsTop.push_back(sin((315+jump-100)*DegToRad)/4.0);
			_yPositionsTop.push_back(-0.5);
		}
		jump+=30;
	}

	//SQUARE -> POINTS AND NORMALS
	jump=0;
	for (int i=0; i<13;i++){
		switch(orient){
			case 1:
				xInit+=jump;
				_xPositions.push_back(xInit);
				_zPositions.push_back(zInit);
				_xPositionsBase.push_back(0);
				_zPositionsBase.push_back(1);
				_yPositionsBase.push_back(0);
				break;
			case 2:
				zInit-=jump;
				_xPositions.push_back(xInit);
				_zPositions.push_back(zInit);
				_xPositionsBase.push_back(1);
				_zPositionsBase.push_back(0);
				_yPositionsBase.push_back(0);
				break;
			case 3:
				xInit-=jump;
				_xPositions.push_back(xInit);
				_zPositions.push_back(zInit);
				_xPositionsBase.push_back(0);
				_zPositionsBase.push_back(-1);
				_yPositionsBase.push_back(0);
			case 4:
				zInit+=jump;
				_xPositions.push_back(xInit);
				_zPositions.push_back(zInit);
				_xPositionsBase.push_back(-1);
				_zPositionsBase.push_back(0);
				_yPositionsBase.push_back(0);
				break;
			default:
				break;
		}
		if(i == 3){
			_xPositions.push_back(0.5);
			_zPositions.push_back(0.5);
			_xPositionsBase.push_back(1);
			_zPositionsBase.push_back(0);
			_yPositionsBase.push_back(0);
			orient++;
		}
		if(i == 6){
			_xPositions.push_back(0.5);
			_zPositions.push_back(-0.5);
			_xPositionsBase.push_back(0);
			_zPositionsBase.push_back(-1);
			_yPositionsBase.push_back(0);
			orient++;
		}
		if(i == 9){
			_xPositions.push_back(-0.5);
			_zPositions.push_back(-0.5);
			_xPositionsBase.push_back(-1);
			_zPositionsBase.push_back(0);
			_yPositionsBase.push_back(0);
			orient++;
		}


		}

	//CALCULATE OF DELTA (dist between square and circle) to get robot points positions
	for (int i=0; i<16;i++){
		_deltaX.push_back(_xPositionsCircle[i]-_xPositions[i]);
		_deltaZ.push_back(_zPositionsCircle[i]-_zPositions[i]);
	}
	
	//Robot Points
	for(int i=0;i<16;i++){
		vector <double> xPos;
		vector <double> zPos;
		for (int j=0; j<=_stacks;j++){
			xPos.push_back(_xPositions[i]+ _deltaX[i]*j*(1.0/_stacks));
			zPos.push_back(_zPositions[i]+ _deltaZ[i]*j*(1.0/_stacks));
		}
		_DrawX.push_back(xPos);
		_DrawZ.push_back(zPos);
	}
}

/*void Robot::setAngle(float angle){
	_angle = angle;
}

void Robot::setPosition(float xpos, float ypos, float zpos){
	_xpos=xpos;
	_ypos=ypos;
	_zpos=zpos;
}*/


void Robot::draw() {
		double dx = 1/3 , alpha = -5 * PI / 4 , dalpha = -PI / 6 ;
		float jump=30;
		glDisable(GL_CULL_FACE);

		if(!_textured)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	//TOP
		glPushMatrix();
		glTranslated(0, 0.9+_ypos, 0);
			glBegin(GL_POLYGON);
			for (float i=15.0; i<375.0; i+=jump) {
					glNormal3d(0,1,0);
					glVertex3d(sin(DegToRad*i)/4, 0, cos(DegToRad*i)/4);
				}
			glEnd();
		glPopMatrix();
	//BOTTOM
		glPushMatrix();
			glNormal3d(0, 1, 0);
			glTranslated(_xpos, _ypos, _zpos);
			glRotated(_angle, 0, 1, 0);
			glBegin(GL_POLYGON);
				glVertex3d(-0.5, 0, -0.5);
				glVertex3d(0.5, 0, -0.5);
				glVertex3d(0.5, 0, 0.5);
				glVertex3d(-0.5, 0, 0.5);
			glEnd();

	//DRAW ROBOT
		for (int i=0; i<15; i++){
		glBegin(GL_TRIANGLE_STRIP);
			for (int j=0; j<=_stacks; j++){
				glTexCoord2d(_DrawX[i][j] + 0.5, 0.5 - _DrawZ[i][j]);
				glNormal3d(_DrawX[i][j], 0, _DrawZ[i][j]);
				glVertex3d(_DrawX[i][j], (double)j/_stacks, _DrawZ[i][j]);

				glTexCoord2d(_DrawX[i+1][j] + 0.5, 0.5 - _DrawZ[i+1][j]);
				glNormal3d(_DrawX[i+1][j], 0, _DrawZ[i+1][j]);
				glVertex3d(_DrawX[i+1][j], (double)j/_stacks, _DrawZ[i+1][j]);
			}
		glEnd();
		}
		glPopMatrix();
		glEnable(GL_CULL_FACE);
		glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );


		




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





