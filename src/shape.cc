#include "shape.hh"

#include <GL/glut.h>

void
Shapes::Polygons(b2Vec2 pos, b2Vec2 size, float cornerCount, float angle)
{
    Shapes::Polygons(pos.x, pos.y, size.x, size.y, cornerCount, angle);
}

void
Shapes::Polygons(float posX, float posY, float sizeX, float sizeY, float cornerCount, float angle)
{
    glBegin(GL_LINE_LOOP);
        float _angle = (0.0f - cornerCount) + angle;
        for (int _k = 0; _k < cornerCount; ++_k)
		{
            glVertex2f(posX + (sizeX * cos(_angle)), posY + (sizeY * sin(_angle)));
            _angle += (360.0f / cornerCount) * M_PI / 180.0f;
        }
    glEnd();
}