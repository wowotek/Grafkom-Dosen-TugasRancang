#ifndef SHAPE_HH
#define SHAPE_HH

#include <Box2D/Box2D.h>

namespace Shapes
{
    void Polygons(b2Vec2 pos, b2Vec2 size, float cornerCount, float angle);
    void Polygons(float posX, float posY, float sizeX, float sizeY, float cornerCount, float angle);
}


#endif