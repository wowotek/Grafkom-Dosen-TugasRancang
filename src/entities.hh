#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "common.hh"

#define ENTITIES_SQUARE 0
#define ENTITIES_CIRCLE 1
#define ENTITIES_TRINGALE 2

class Entities
{
    private:
        vec2f pos;
        int type;

        void DrawSquare(void);
        void DrawEllipse(void);
        void DrawTriangle(void);

    public:
        Entities(float, float, int);
        Entities(vec2f, int);

        void DrawEntities(void);
};

#endif