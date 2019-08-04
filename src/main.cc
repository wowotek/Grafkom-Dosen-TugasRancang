#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "shape.hh"
#include "entity.hh"
#include "control.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

float windowWidth = WINDOW_WIDTH;
float windowHeight = WINDOW_HEIGHT;

b2Vec2 gravity(0.0f, 1.6f);
b2World world(gravity);
std::vector<Entity> entities;

void
RenderScreen()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    for(size_t i=0; i<entities.size(); i++)
    {
        entities.at(i).DrawEntity();
    }

    glutSwapBuffers();
}

void
Blit(int rate)
{
    world.Step((1.0f/60.0f), 10, 10);

    glutSwapBuffers();
    glutPostRedisplay();
    glutTimerFunc(rate, Blit, rate);
}

void
OnWindowReshape(int newWidth, int newHeight)
{
    glViewport(0, 0, newWidth, newHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(
        0, ((float)(newWidth)/(float)(WINDOW_WIDTH) * 10),
        ((float)(newHeight)/(float)(WINDOW_WIDTH) * 10), 0
    );

    windowWidth = newWidth;
    windowHeight = newHeight;
}

void
InitializeStaticBodies()
{
    /* Bottom Floor */ {
        b2BodyDef bottomBodyDef;
        bottomBodyDef.position.Set(-10.0f, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10)+1.0);
        b2Body * bottomBody = world.CreateBody(&bottomBodyDef);
        b2PolygonShape bottomBodyShape;
        bottomBodyShape.SetAsBox(200, 1.0f);
        bottomBody->CreateFixture(&bottomBodyShape, 0.0f);
    }
    /* Top Ceiling */ {
        b2BodyDef topBodyDef;
        topBodyDef.position.Set(-10.0f, -1);
        b2Body * topBody = world.CreateBody(&topBodyDef);
        b2PolygonShape topBodyShape;
        topBodyShape.SetAsBox(200, 1.0f);
        topBody->CreateFixture(&topBodyShape, 0.0f);
    }

    /* Left Wall */ {
        b2BodyDef leftBodyDef;
        leftBodyDef.position.Set(0, 0);
        b2Body * leftBody = world.CreateBody(&leftBodyDef);
        b2PolygonShape leftBodyShape;

        b2Vec2 leftWallVertices[4] = {
            b2Vec2(0, 0),
            b2Vec2(-1, 0),
            b2Vec2(-1, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10)),
            b2Vec2(0, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10))
        };

        leftBodyShape.Set(leftWallVertices, 4);
        leftBody->CreateFixture(&leftBodyShape, 0.0f);
    }

    /* Right Wall */ {
        b2BodyDef leftBodyDef;
        leftBodyDef.position.Set(0, 0);
        b2Body * leftBody = world.CreateBody(&leftBodyDef);
        b2PolygonShape leftBodyShape;

        b2Vec2 leftWallVertices[4] = {
            b2Vec2(0, 0),
            b2Vec2(-1, 0),
            b2Vec2(-1, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10)),
            b2Vec2(0, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10))
        };

        leftBodyShape.Set(leftWallVertices, 4);
        leftBody->CreateFixture(&leftBodyShape, 0.0f);
    }
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

    InitControl(&entities, &world, &windowWidth, &windowHeight);

    glutKeyboardFunc(KeyboardDownHandler);
    glutMouseFunc(MouseDownHandler);

    glutTimerFunc(0, Blit, 16);

    SetShapesDrawMode(GL_LINE_LOOP);

    InitializeStaticBodies();

    glutMainLoop();

    return 0;
}