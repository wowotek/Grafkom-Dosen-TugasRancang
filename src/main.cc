#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

void Poly(float TITIK_LAYAR_X, float TITIK_LAYAR_Y, float LEBAR_X, float LEBAR_Y, float JUMLAH_SUDUT, float ROTASI)
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
    glBegin(GL_LINE_LOOP);
        glColor3f(1.0, 1.0, 0);
        glVertex2i(15, 40);
        glVertex2i(30, 40);
        glVertex2i(30, 60);
        glVertex2i(15, 60);
    glEnd();

    glBegin(GL_LINE_LOOP);
        glColor3f(1, 0, 0);
        glVertex2i(40, 40);
        glVertex2i(55, 40);
        glVertex2i(47, 60);
    glEnd();

    glColor3f(0, 1, 0);
    for(int i = 0; i < 35; i++)
	{
		lingkaran(20, 25, 20, 20, 1000, 20);
	}

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tugas Rancang");
    glLineWidth(5.0);
    glutDisplayFunc(myDisplay);
    gluOrtho2D(0, 100, 0, 100);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}