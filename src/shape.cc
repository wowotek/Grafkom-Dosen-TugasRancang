/* implement entities shape, all vertices defined here
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

#include <iostream>
#include <GL/glut.h>

#include "shape.hh"

uint DRAWMODE = GL_LINE_LOOP;
uint * texShapeP;

b2Vec2 sqTexCoord[4] = {
    b2Vec2(0, 0),
    b2Vec2(0, 1),
    b2Vec2(1, 1),
    b2Vec2(1, 0),
};

b2Vec2 trTexCoord[4] = {
    b2Vec2(0.5, 0),
    b2Vec2(0, 1),
    b2Vec2(1, 1),
};

b2Vec2 crTexCoord[360];

void
InitShapeTextures(unsigned int * initTexture)
{
    texShapeP = initTexture;

    for(int i=0; i<360; i++){
        crTexCoord[i].Set(
            cos(((float)(i) * ((2.0f * M_PI) / static_cast<float>(360)))),
            sin(((float)(i) * ((2.0f * M_PI) / static_cast<float>(360))))
        );
    }
}


void
SetShapesDrawMode(uint mode)
{
    DRAWMODE = mode;
}

void
Square(b2Vec2 pos, float size, float angle, unsigned int texture)
{
    float step = ((2.0f * M_PI) / static_cast<float>(4));
    angle = angle - (0.25 * M_PI);

    if(texture != -1){
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(DRAWMODE);
    for(uint8 i = 0; i < 4; ++i){
        glTexCoord2f(
            sqTexCoord[i].x,
            sqTexCoord[i].y
        );
        glVertex2f(
            pos.x + cos((i * step)+angle) * size,
            pos.y + sin((i * step)+angle) * size
        );
    }
    glEnd();
}

void
Triangle(b2Vec2 pos, float size, float angle, unsigned int texture)
{
    float step = ((2.0f * M_PI) / static_cast<float>(3));
    angle = angle - (0.5 * M_PI);

    if(texture != -1){
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(DRAWMODE);
    for(uint8 i = 0; i < 3; ++i){
        glTexCoord2f(
            trTexCoord[i].x,
            trTexCoord[i].y
        );
        glVertex2f(
            pos.x + cos((i * step)+angle) * size,
            pos.y + sin((i * step)+angle) * size
        );
    }
    glEnd();
}

void
Circle(b2Vec2 pos, float size, float angle, unsigned int texture)
{
    float step = ((2.0f * M_PI) / static_cast<float>(360));

    if(texture != -1){
        glColor3f(1, 1, 1);
        glBindTexture(GL_TEXTURE_2D, texture);
    } else {
        glColor3f(1, 0, 0);
    }
    glBegin(DRAWMODE);
    for(uint16 i = 0; i < 360; ++i){
        glTexCoord2f(
            crTexCoord[i].x,
            crTexCoord[i].y
        );
        glVertex2f(
            pos.x + cos((i * step)+angle) * size,
            pos.y + sin((i * step)+angle) * size
        );
    }
    glEnd();
}