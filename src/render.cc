#include "render.hh"

#include <iostream>
#include <chrono>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "game.hh"

b2World * Rworld;

void
InitRenderer(b2World * init_world)
{
    Rworld = init_world;
    InitGame(Rworld);
}

void
RenderDisplay(void)
{
    glClearColor(1.0f, 1.00f, 1.00f, 1.00f);
    glClear(GL_COLOR_BUFFER_BIT);

    RenderEntities();

    glutSwapBuffers();
}

auto start = std::chrono::high_resolution_clock::now();
void
Blit(int)
{
    Rworld->Step(1.0f/60.0f, 1, 1);
    Rworld->DrawDebugData();
    UpdateEntities();

    glutPostRedisplay();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    start = std::chrono::high_resolution_clock::now();
    std::cout << "Last Update : " << elapsed.count() << "                                        \r";
    fflush(stdout);

    //Rworld->ClearForces();
    glutTimerFunc(0, Blit, 0);
}
