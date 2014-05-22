#ifndef Robot_H
#define Robot_H

#include "CGFappearance.h"
#include "CGFobject.h"

class Robot 
{
	public:
		Robot(double xpos, double ypos, double zpos, double yOrient, int stacks);

		void move(int dir);
		void rotate(int dir);
		void draw();
	

	private:
		//CGFappearance* rAppearance;
		double _xpos,_ypos,_zpos;
		int _angle , _stacks;
		

			
		bool _textured;
};

#endif