#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "common.hh"

class Entity
{
    private:
        vec2f pos;
        int type;
        int frame;

        void DrawSquare(void);
        void DrawEllipse(void);
        void DrawTriangle(void);

    public:
        Entity(float, float, int);
        Entity(vec2f, int);

        void DrawEntity(void);
        void UpdateEntity(void);
};

#endif