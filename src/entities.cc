#include "entities.hh"

Entities::Entities(float init_x, float init_y, int init_type)
{
    pos = vec2f(init_x, init_y);
    type = init_type;
}

Entities::Entities(vec2f init_pos, int init_type)
{
    pos = init_pos;
    type = init_type;
}

void
Entities::DrawEntities(void)
{
    glColor3f(1, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(pos.x - 10, pos.y - 10);
        glVertex2f(pos.x - 10, pos.y + 10);
        glVertex2f(pos.x + 10, pos.y + 10);
        glVertex2f(pos.x + 10, pos.y - 10);
    glEnd();
}