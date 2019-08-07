/* defining implementation of entities shapes, and vertices
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

#ifndef SHAPE_HH
#define SHAPE_HH

#include <Box2D/Box2D.h>
#include <GL/glut.h>

void InitShapeTextures(unsigned int *);
void SetShapesDrawMode(uint);

void Square(b2Vec2, float, float, unsigned int);
void Triangle(b2Vec2, float, float, unsigned int);
void Circle(b2Vec2, float, float, unsigned int);

#endif