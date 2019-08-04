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