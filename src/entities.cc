#include "entities.hpp"

Entities::Entities(float init_x, float init_y)
{
    x = init_x;
    y = init_y;
}

void
Entities::DrawEntities(void)
{
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(x - (ukuranKotak/2), y - (ukuranKotak/2));
        glVertex2f(x - (ukuranKotak/2), y + (ukuranKotak/2));
        glVertex2f(x + (ukuranKotak/2), y + (ukuranKotak/2));
        glVertex2f(x + (ukuranKotak/2), y - (ukuranKotak/2));
    glEnd();
}