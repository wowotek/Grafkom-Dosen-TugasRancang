/* implementation of control.hh, handle all of the game control
 * Copyright (C) 2019  Erlangga Ibrahim, Aurelia Gabriele
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include "control.hh"
#include <iostream>

b2World * worldP;
std::vector<Entity> * entitiesP;
Spring * springControlPointer;

EntityType currentType = SQUARE;
bool isCreatingEntity = true;

float * widthP;
float * heightP;

b2Vec2 mousePos;

void
InitControl(std::vector<Entity> * initEntities, b2World * initWorld, Spring * initSpring, float * initW, float * initH)
{
    entitiesP = initEntities;
    worldP = initWorld;
    springControlPointer = initSpring;

    springControlPointer->SetMousePos(&mousePos);
    springControlPointer->SetWorld(worldP);
    springControlPointer->SetGroundBody();

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

    mousePos.Set((float)nx, (float)ny);
    
    if(button == 0 && state == 1) {
        if(isCreatingEntity){
            Entity e(mousePos, 0.25, currentType, worldP);

            entitiesP->push_back(e);
        } else {
            for(uint i=0; i<entitiesP->size(); i++){
                springControlPointer->Update();
                if(entitiesP->at(i).IsMouseInside(springControlPointer->mousePosition->x, springControlPointer->mousePosition->y)){
                    springControlPointer->Joint(entitiesP->at(i).body);
                }
            }
        }
    } else if (button == 0 && state == 0) {
        if(!isCreatingEntity) springControlPointer->Detach();
    }
}

void
MouseDragHandler(int x, int y)
{
    float nx = (((float(x)) * (((float)(*widthP)/(float)(800) * 10.0f)))
            / ((float)(*widthP)));
    float ny = (((float(y)) * (((float)(*heightP)/(float)(800) * 10.0f)))
            / ((float)(*heightP)));
    mousePos.Set((float)(nx), (float)(ny));
    springControlPointer->Update();
}

void
MouseHoverHandler(int x, int y)
{
    float nx = (((float(x)) * (((float)(*widthP)/(float)(800) * 10.0f)))
            / ((float)(*widthP)));
    float ny = (((float(y)) * (((float)(*heightP)/(float)(800) * 10.0f)))
            / ((float)(*heightP)));
    mousePos.Set((float)(nx), (float)(ny));
    springControlPointer->Update();
}

void
KeyboardDownHandler(unsigned char key, int x, int y)
{   
    if(key == 'S' || key == 's'){    // Box
        if(currentType != SQUARE){
            currentType = SQUARE;
            std::cout << "Shape Changed to : Square" << std::endl;
        }
    } else 
    if(key == 'A' || key == 'a') {  // Triangle
        if(currentType != TRIANGLE){
            currentType = TRIANGLE;
            std::cout << "Shape Changed to : Triangle" << std::endl;
        }
    } else 
    if(key == 'D' || key == 'd') {  // Circle
        if(currentType != CIRCLE){
            currentType = CIRCLE;
            std::cout << "Shape Changed to : Circle" << std::endl;
        }
    }

    if(key == 'c' || key == 'C') {
        isCreatingEntity = !isCreatingEntity;
        std::cout << "Create Entity on Click is now ";
        std::cout << (isCreatingEntity ? "[ON]" : "[OFF]") << std::endl;
    }

    fflush(stdout);
}