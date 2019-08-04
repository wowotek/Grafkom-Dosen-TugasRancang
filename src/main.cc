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
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <vector>
#include <cmath>

typedef struct {
    GLfloat x;
    GLfloat y;
} koordinat;

std::vector<koordinat> data_koordinat;

void lingkaran(float TITIK_LAYAR_X, float TITIK_LAYAR_Y, float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI)
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
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);
	for(int i=0; i<data_koordinat.size(); i++)
	{
		glPointSize(5.0);
		glBegin(GL_POINTS);
		glVertex2f(data_koordinat[i].x, data_koordinat[i].y);
		glEnd();
	}

    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 0);
        glVertex2i(150, 400);
        glVertex2i(180, 400);
        glVertex2i(180, 430);
        glVertex2i(150, 430);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(1, 0, 0);
        glVertex2i(400, 400);
        glVertex2i(430, 400);
        glVertex2f(411, 430);
    glEnd();

    glColor3f(0, 1, 0);
    for(int i = 0; i < 35; i++)
	{
		lingkaran(400, 400, 20, 20, 1000, 20);
	}

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
void myMouse (int button, int state, int mousex, int mousey)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		koordinat mouseKoord;

		mouseKoord.x = mousex;
		mouseKoord.y = 600 - mousey;
		data_koordinat.push_back(mouseKoord);
	}

	glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tugas Rancang");
    glLineWidth(5.0);
    glutDisplayFunc(myDisplay);
    glutMouseFunc(myMouse);
    gluOrtho2D(0, 800, 0, 600);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}