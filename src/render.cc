#include "render.hh"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "game.hh"

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
    UpdateEntities();

    glutPostRedisplay();
    glutTimerFunc(fps, Blit, fps);
}
