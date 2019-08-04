#ifndef SHAPE_HH
#define SHAPE_HH

#include <Box2D/Box2D.h>
#include <GL/glut.h>

void SetShapesDrawMode(uint);

void Square(b2Vec2, float, float);
void Triangle(b2Vec2, float, float);
void Circle(b2Vec2, float, float);

#endif