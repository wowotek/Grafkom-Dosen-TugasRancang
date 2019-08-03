#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

#include "shape.hh"
#include "entity.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

float windowWidth = WINDOW_WIDTH;
float windowHeight = WINDOW_HEIGHT;

void
RenderScreen()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(5);

    glColor3f(1, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2f(1, 1);
        glVertex2f(1, 2);
        glVertex2f(2, 2);
        glVertex2f(2, 1);
    glEnd();

    glutSwapBuffers();
}

void
OnWindowReshape(int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(
        0, (float)(newWidth)/(float)(WINDOW_WIDTH) * 10,
        (float)(newHeight)/(float)(WINDOW_WIDTH) * 10, 0
    );

    windowWidth = newWidth;
    windowHeight = newHeight;
}

int
main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Tugas Rancang Dosen");
    
    glutDisplayFunc(RenderScreen);
    glutReshapeFunc(OnWindowReshape);

    glutMainLoop();

    return 0;
}