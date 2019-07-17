#include "entities.hpp"

Kotak::Kotak(float init_x, float init_y)
{
    x = init_x;
    y = init_y;
}

void
Kotak::GambarKotak(void)
{
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(x - (ukuranKotak/2), y - (ukuranKotak/2));
        glVertex2f(x - (ukuranKotak/2), y + (ukuranKotak/2));
        glVertex2f(x + (ukuranKotak/2), y + (ukuranKotak/2));
        glVertex2f(x + (ukuranKotak/2), y - (ukuranKotak/2));
    glEnd();
}