#ifndef Robot_H
#define Robot_H

#include "CGFappearance.h"
#include "CGFobject.h"

class Robot 
{
	public:
		Robot(double xpos, double ypos, double zpos, double yOrient, int stacks);
		/*void setPosition(float xpos, float ypos, float zpos);
		void setAngle(float _angle);
		*/
		void draw();
	

	private:
		//CGFappearance* rAppearance;
		double _xpos,_ypos,_zpos;
		int _angle , _stacks;
		vector <double> _xPositions;
		vector <double> _zPositions;
		vector <double> _xPositionsCircle;
		vector <double> _zPositionsCircle;
		vector <double>	_xPositionsBase;
		vector <double> _yPositionsBase;
		vector <double> _zPositionsBase;
		vector <double> _xPositionsTop;
		vector <double> _yPositionsTop;
		vector <double> _zPositionsTop;

		vector <double> _deltaX;
		vector <double> _deltaZ;

		vector <double> _xNormals;
		vector <double> _yNormals;
		vector <double> _zNormals;

		vector <vector <double> > _DrawX;
		vector <vector <double> > _DrawZ;

			
		bool _textured;
};

#endif