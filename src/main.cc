#include <iostream>
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
    GLfloat derajat = (360.0f / JUMLAH_SUDUT) * M_PI / 180.0f;
    glBegin(GL_LINE_LOOP);
        GLfloat sudut = 0.0f - ROTASI;
        for (int _k = 0; _k < JUMLAH_SUDUT; ++_k)
		{
            glVertex2f(TITIK_LAYAR_X + (LEBAR_X * cos(sudut)), TITIK_LAYAR_Y + (LEBAR_Y * sin(sudut)));
            sudut += derajat;
        }
    glEnd();

}

void myDisplay()
{
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

    glutSwapBuffers();
}

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