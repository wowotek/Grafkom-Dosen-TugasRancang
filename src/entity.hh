#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <Box2D/Box2D.h>

#include "common.hh"

class Entity
{
    private:
        vec2f pos;
        int type;

        b2BodyDef bodyDef;
        b2Body * body;
        b2PolygonShape bodyShape;
        b2FixtureDef fixtureDef;

        void DrawSquare(void);
        void DrawEllipse(void);
        void DrawTriangle(void);

        void InitPhysicalBody(b2World*, vec2f);

    public:
        Entity(float, float, int, b2World*);
        Entity(vec2f, int, b2World*);

        void DrawEntity(void);
        void UpdateEntity(void);
};
#endif