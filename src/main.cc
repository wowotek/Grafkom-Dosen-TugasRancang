#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>

#include "shape.hh"

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

    // glColor3f(0, 1, 0);
    // for(int i = 0; i < 35; i++)
	// {
	// 	lingkaran(20, 25, 20, 20, 1000, 20);
	// }

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tugas Rancang Dosen");
    glLineWidth(5.0);
    glutDisplayFunc(myDisplay);
    gluOrtho2D(0, 100, 0, 100);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}