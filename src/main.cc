/* main programs, all function should be called or used here
 * Copyright (C) 2019  Erlangga Ibrahim, Aurelia Gabriele
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

#include "shape.hh"
#include "entity.hh"
#include "control.hh"
#include "texture.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

float windowWidth = WINDOW_WIDTH;
float windowHeight = WINDOW_HEIGHT;

unsigned int * mattextures;

b2Vec2 gravity(0.0f, 9.82f);
b2World world(gravity);
std::vector<Entity> entities;

Spring mouseSpring;

void
RenderScreen()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    glBindTexture(GL_TEXTURE_2D, mattextures[2]);
    glBegin(GL_POLYGON);
        glTexCoord2f(0, 1); glVertex2f(0, 0);
        glTexCoord2f(1, 1); glVertex2f(((float)(windowWidth)/(float)(WINDOW_WIDTH) * 10), 0);
        glTexCoord2f(1, 0); glVertex2f(((float)(windowWidth)/(float)(WINDOW_WIDTH) * 10), ((float)(windowHeight)/(float)(WINDOW_WIDTH)*10));
        glTexCoord2f(0, 0); glVertex2f(0, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10));
    glEnd();

    mouseSpring.Update();
    for(size_t i=0; i<entities.size(); i++)
    {
        entities.at(i).DrawEntity();
    }

    mouseSpring.Update();
    glutSwapBuffers();
}

void
Blit(int rate)
{
    world.Step((1.0f/60.0f), 10, 10);
    mouseSpring.Update();
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
InitStaticBodies()
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
        b2BodyDef rightBodyDef;
        rightBodyDef.position.Set(0, 0);
        b2Body * rightBody = world.CreateBody(&rightBodyDef);
        b2PolygonShape rightBodyShape;

        float w = ((float)(windowWidth)/(float)(WINDOW_WIDTH) * 10);
        float h = ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10);
        b2Vec2 rightWallVertices[4] = {
            b2Vec2(w+10, 0),
            b2Vec2(w, 0),
            b2Vec2(w, h),
            b2Vec2(w+10, h)
        };

        rightBodyShape.Set(rightWallVertices, 4);
        rightBody->CreateFixture(&rightBodyShape, 0.0f);
    }

}

void
InitTextures()
{
    mattextures = new unsigned int[3];
    glGenTextures(3, mattextures);
    LoadTexture(mattextures[0], "data/brick.bmp", 512, 512);
    LoadTexture(mattextures[1], "data/rubber.bmp", 512, 512);
    LoadTexture(mattextures[2], "data/bg.bmp", 420, 420);

    InitShapeTextures(mattextures);
    InitEntityTextures(mattextures);
}

int
main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutSetOption(GLUT_MULTISAMPLE, 16);
    glHint(GL_MULTISAMPLE_FILTER_HINT_NV, GL_NICEST);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glEnable(GL_LINE_SMOOTH);
    glHint(GL_LINE_SMOOTH, GL_NICEST);

    glEnable(GL_POINT_SMOOTH);
    glHint(GL_POINT_SMOOTH, GL_NICEST);

    glShadeModel(GL_SMOOTH); 
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 


    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Tugas Rancang Dosen");
    
    InitTextures();
    glEnable(GL_TEXTURE_2D);
    InitControl(&entities, &world, &mouseSpring, &windowWidth, &windowHeight);
    InitStaticBodies();

    glutDisplayFunc(RenderScreen);
    glutReshapeFunc(OnWindowReshape);
    glutKeyboardFunc(KeyboardDownHandler);
    glutMotionFunc(MouseDragHandler);
    glutPassiveMotionFunc(MouseHoverHandler);
    glutMouseFunc(MouseDownHandler);

    glutTimerFunc(0, Blit, 16);

    SetShapesDrawMode(GL_POLYGON);

    glutMainLoop();

    return 0;
}
