#ifndef MY_CYLINDER
#define MY_CYLINDER

#include "CGFobject.h"

#include <vector>

typedef struct coordinate {
    float x;
    float y;
    float z;
} crd;

class Cylinder : public CGFobject {
    
private:
    
    int _slices;
    int _stacks;
    
    bool _smooth;
    
    bool _isClock;
    
    std::vector<coordinate> _vertices;
    
public:
    
    Cylinder(int slices, int stacks, bool smooth);
    
    void draw();
    
    void setIsClock(bool cl);
    
};



#endif
