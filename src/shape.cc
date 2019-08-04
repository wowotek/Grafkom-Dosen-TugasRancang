#include <iostream>
#include <GL/glut.h>

#include "shape.hh"

uint DRAWMODE = GL_LINE_LOOP;

void
SetShapesDrawMode(uint mode)
{
    DRAWMODE = mode;
}

void
Square(b2Vec2 pos, float size, float angle)
{
    float step = ((2.0f * M_PI) / static_cast<float>(4));
    angle = angle - (0.25 * M_PI);

    glColor3f(0.8, 0, 0);
    glBegin(DRAWMODE);
    for(uint8 i = 0; i < 4; ++i){
        glVertex2f(
            pos.x + cos((i * step)+angle) * size,
            pos.y + sin((i * step)+angle) * size
        );
    }
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(pos.x, pos.y);
    glEnd();
}

void
Triangle(b2Vec2 pos, float size, float angle)
{
    float step = ((2.0f * M_PI) / static_cast<float>(3));
    angle = angle - (0.5 * M_PI);

    glColor3f(0.8, 0, 0);
    glBegin(DRAWMODE);
    for(uint8 i = 0; i < 3; ++i){
        glVertex2f(
            pos.x + cos((i * step)+angle) * size,
            pos.y + sin((i * step)+angle) * size
        );
    }
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(pos.x, pos.y);
    glEnd();
}

void
Circle(b2Vec2 pos, float size, float angle)
{
    float step = ((2.0f * M_PI) / static_cast<float>(360));

    glColor3f(1, 0, 0);
    glBegin(DRAWMODE);
    for(uint16 i = 0; i < 360; ++i){
        glVertex2f(
            pos.x + cos((i * step)+angle) * size,
            pos.y + sin((i * step)+angle) * size
        );
    }
    glEnd();

    glColor3f(0, 1, 0);
    glBegin(DRAWMODE);
    glVertex2f(pos.x, pos.y);
    for(uint16 i = 0; i < 360; ++i){
        if(i >= 0 && i <= 11){
            glVertex2f(
                pos.x + cos((i * step)+angle) * size,
                pos.y + sin((i * step)+angle) * size
            );
        }
    }
    glEnd();
}