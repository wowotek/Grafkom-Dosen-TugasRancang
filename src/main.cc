#include <iostream>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "shape.hh"
#include "entity.hh"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

float windowWidth = WINDOW_WIDTH;
float windowHeight = WINDOW_HEIGHT;

b2Vec2 gravity(0.0f, 9.82f);
b2World world(gravity);

Entity e1(
    b2Vec2(1, 1), 0.25, 
    CIRCLE, &world
);

void
RenderScreen()
{
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    e1.DrawEntity();

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

void
Blit(int rate)
{
    world.Step((1.0f/60.0f), 4, 6);
    b2Vec2 pos = e1.body->GetPosition();

    //std::cout << pos.x << " " << pos.y << std::endl;
    glutSwapBuffers();
    glutPostRedisplay();
    glutTimerFunc(rate, Blit, rate);
}

// void myMouse (int button, int state, int mousex, int mousey)
// {
// 	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
// 	{
// 		koordinat mouseKoord;

// 		mouseKoord.x = mousex;
// 		mouseKoord.y = 600 - mousey;
// 		data_koordinat.push_back(mouseKoord);
// 	}

// 	glutPostRedisplay();
// }


int
main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(windowWidth, windowHeight);
    glutCreateWindow("Tugas Rancang Dosen");
    
    glutDisplayFunc(RenderScreen);
    glutReshapeFunc(OnWindowReshape); 
    glutTimerFunc(0, Blit, 16);

    SetShapesDrawMode(GL_TRIANGLE_FAN);
    b2BodyDef gbd;
    gbd.position.Set(4.0f, ((float)(windowHeight)/(float)(WINDOW_WIDTH) * 10));
    
    b2Body * gb = world.CreateBody(&gbd);
    b2PolygonShape gbp;
    gbp.SetAsBox(1, 0.1f);

    gb->CreateFixture(&gbp, 0.0f);
    
    glutMainLoop();

    return 0;
}