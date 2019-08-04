#include "control.hh"
#include <iostream>

b2World * worldP;
std::vector<Entity> * entitiesP;

EntityType currentType = SQUARE;
float * widthP;
float * heightP;

void
InitControl(std::vector<Entity> * initEntities, b2World * initWorld, float * initW, float * initH)
{
    entitiesP = initEntities;
    worldP = initWorld;

    widthP = initW;
    heightP = initH;
}

void
MouseDownHandler(int button, int state, int x, int y)
{
    //NewValue = (((OldValue - OldMin) * (NewMax - NewMin)) / (OldMax - OldMin)) + NewMin
    float nx = (((float(x)) * (((float)(*widthP)/(float)(800) * 10.0f)))
             / ((float)(*widthP)));
    float ny = (((float(y)) * (((float)(*heightP)/(float)(800) * 10.0f)))
             / ((float)(*heightP)));
    
    if(button == 0 && state == 1) {
        b2Vec2 cPos((float)nx, (float)ny);
        Entity e(cPos, 0.25, currentType, worldP);

        entitiesP->push_back(e);
    }
}

void
KeyboardDownHandler(unsigned char key, int x, int y)
{
    if(key == 'B' || key == 'b'){    // Box
        if(currentType != SQUARE){
            currentType = SQUARE;
            std::cout << "Shape Changed to : Square" << std::endl;
        }
    } else 
    if (key == 'T' || key == 't') {  // Triangle
        if(currentType != TRIANGLE){
            currentType = TRIANGLE;
            std::cout << "Shape Changed to : Triangle" << std::endl;
        }
    } else 
    if (key == 'C' || key == 'c') {  // Circle
        if(currentType != CIRCLE){
            currentType = CIRCLE;
            std::cout << "Shape Changed to : Circle" << std::endl;
        }
    }

    fflush(stdout);
}