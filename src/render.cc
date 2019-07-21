#include "render.hh"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "game.hh"

void
InitRenderer(b2World * world)
{
    InitGame(world);
}

void
RenderDisplay(void)
{
    glClearColor(1.0f, 1.00f, 1.00f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

    RenderEntities();

    glutSwapBuffers();
}

void
Blit(int fps)
{
    UpdateEntities(fps);

    glutPostRedisplay();
    glutTimerFunc(fps, Blit, 0);
}
