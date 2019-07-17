#ifndef ENTITIES_HPP
#define ENTITIES_HPP

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

class Entities
{
    private:
        float x, y;
        float ukuranKotak = 20;

    public:
        Entities(float, float);
        void DrawEntities(void);
};

#endif