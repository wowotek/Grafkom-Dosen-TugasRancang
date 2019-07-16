#include "render.hpp"

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

class Kotak{
    float x, y;

    float ukuranKotak = 20;

    void
    GambarKotak(void)
    {
        glColor3f(1, 0, 0);
        glBegin(GL_QUADS);
            glVertex2f(x - (ukuranKotak/2), y - (ukuranKotak/2));
            glVertex2f(x - (ukuranKotak/2), y + (ukuranKotak/2));
            glVertex2f(x + (ukuranKotak/2), y + (ukuranKotak/2));
            glVertex2f(x + (ukuranKotak/2), y - (ukuranKotak/2));
        glEnd();
    }
};

Kotak k = new Kotak(50, 50);
void
RenderDisplay(void)
{
    k.GambarKotak();
    glutSwapBuffers();
}

void
Blit(int fps)
{
    glutPostRedisplay();
    glutTimerFunc(fps, Blit, fps);
}
