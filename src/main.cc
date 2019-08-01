#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 0.3);
    glBegin(GL_LINE_LOOP);
        glVertex2i(30, 30);
        glVertex2i(60, 30);
        glVertex2i(60, 60);
        glVertex2i(30, 60);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE || GLUT_RGBA);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Tugas Rancang");
    glutDisplayFunc(myDisplay);
    gluOrtho2D(0, 100, 0, 100);
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}