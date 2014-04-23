#include <cmath>

#include "CGFappearance.h"

#include "Cylinder.h"

#include "CylinderSlice.h"

static float pi = acos(-1.0);

Cylinder::Cylinder(int slices, int stacks, bool smooth) {
	_slices = slices;
    _stacks = stacks;
    
    _smooth = smooth;
}

void Cylinder::setIsClock(bool cl) {
    _isClock = cl;
}

void Cylinder::draw() {
    if (_slices < 3 || _stacks < 1)
        return;
    
    for (int i = 0; i < _stacks; i++) {
        glPushMatrix();
        
        glTranslated(0, i, 0);
        
        CylinderSlice *sl = new CylinderSlice(_slices, _smooth);
        
        if (!i && _isClock) {
            sl->setIsClockBase(true);
        }
        
        sl -> draw();
        
        glEnable(GL_TEXTURE);
        
        glPopMatrix();
    }
}
