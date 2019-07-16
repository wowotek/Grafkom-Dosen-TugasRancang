#include <iostream>
#include <string.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "control.hpp"
#include "render.hpp"

#define WIDTH 800
#define HEIGHT 600

void
Blit(int fps)
{
    glutTimerFunc(fps, Blit, fps);
}

void
Init(void)
{
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutSetOption(GLUT_MULTISAMPLE, 16);

    glEnable(GL_MULTISAMPLE);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

    glutDisplayFunc(RenderDisplay);

    glutMouseFunc(MouseEvent);
    glutKeyboardFunc(KeyboardDownEvent);
    glutKeyboardUpFunc(KeyboardUpEvent);

    Blit(1000/60);

    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);
}

int 
main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(2280, 480);
    glutCreateWindow("TUGAS 4 GRAFKOM");

    Init();

    glutMainLoop();
    return 0;
}