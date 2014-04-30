#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "Table.h"
#include "Plane.h"
#include "Chair.h"
#include "Clock.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();

	CGFlight* light0;
	CGFlight* light1;
    CGFlight* light2;
    CGFlight* light3;

	Table* table;
    Chair* chair;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	Clock* clock;
	CGFappearance* materialA;
	CGFappearance* materialB;
    CGFappearance* materialFW;
    CGFappearance* tableAppearance;
    CGFappearance* windowAppearance;
    CGFappearance* floorAppearance;
	~LightingScene();

	unsigned long _last_time_ms;
    
    void update(unsigned long ms);
};

#endif