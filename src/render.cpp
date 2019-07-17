#include "render.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "entities.hpp"

Kotak k(50, 50);

void
RenderDisplay(void)
{
    k.GambarKotak();
    glutSwapBuffers();
}

void
Blit(int fps)
{
    glutPostRedisplay();
    glutTimerFunc(fps, Blit, fps);
}
