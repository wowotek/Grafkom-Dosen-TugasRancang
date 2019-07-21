#include <iostream>
#include <string.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include <Box2D/Box2D.h>

#include "control.hh"
#include "render.hh"
#include "common.hh"

#define WIDTH 800
#define HEIGHT 600

int 
main(int argc, char ** argv)
{
    printoutln("Program Executed");
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_MULTISAMPLE);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(400, 200);
    printoutln("Glut Initialized, creating Window...");
    glutCreateWindow("TUGAS 4 GRAFKOM");

    printoutln("Window Created, Configuring World...");
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);

    glutSetOption(GLUT_MULTISAMPLE, 16);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);
    glEnable(GL_MULTISAMPLE);

    glutDisplayFunc(RenderDisplay);

    glutMouseFunc(MouseEvent);
    glutKeyboardFunc(KeyboardDownEvent);
    glutKeyboardUpFunc(KeyboardUpEvent);

    gluOrtho2D(0, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT), 0);
    
    b2World world(b2Vec2(0.0f, 0.982f));
    InitRenderer(&world);

    printoutln("World Configured, Entering Main Loop..." << std::endl << std::endl);
    
    Blit(0);
    glutMainLoop();


    return 0;
}