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

        void DrawSquare(void);
        void DrawEllipse(void);
        void DrawTriangle(void);

        void Init(void);

    public:
        Entity(float, float, int);
        Entity(vec2f, int);

        void DrawEntity(void);
        void UpdateEntity(void);
};

class Body
{
    private:
        b2BodyDef bodyDef;
        b2Body* body;
        b2PolygonShape box;
        b2FixtureDef fixtureDef;

        vec2f pos;
    
    public:
        Body(b2World, int, int, vec2f, vec2f);
};

#endif