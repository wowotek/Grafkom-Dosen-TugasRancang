#include "render.hh"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "entities.hh"

Entities k(50, 50);

void
RenderDisplay(void)
{
    k.DrawEntities();
    glutSwapBuffers();
}

void
Blit(int fps)
{
    glutPostRedisplay();
    glutTimerFunc(fps, Blit, fps);
}
