#ifndef Robot_H
#define Robot_H

#include "CGFappearance.h"
#include "CGFobject.h"

class Robot 
{
	public:
		Robot(int stacks);
		void setPosition(float xpos, float ypos, float zpos);
		void setAngle(float _angle);
		void draw();
	

	private:
		//CGFappearance* rAppearance;
		float _xpos,_ypos,_zpos;
		int _angle , _stacks, _slices;
};

#endif