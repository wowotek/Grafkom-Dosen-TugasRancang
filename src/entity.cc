#include "entity.hh"

Entity::Entity(float init_x, float init_y, int init_type)
{
    pos = vec2f(init_x, init_y);
    type = init_type;
}

Entity::Entity(vec2f init_pos, int init_type)
{
    pos = init_pos;
    type = init_type;
}

void
Entity::DrawEntity(void)
{
    glLineWidth(2);
    glPointSize(2);
    glColor3f(1, 0, 0);

    if (type == ENTITY_TRIANGLE)      // TRIANGLE
    {
        DrawTriangle();
    } 
    else if (type == ENTITY_CIRCLE)   // CIRCLE
    {
        DrawEllipse();
    }
    else                                // SQUARE
    {
        DrawSquare();
    }
}

void
Entity::UpdateEntity(void)
{
    pos += vec2f(0, 1);
}

void
Entity::DrawSquare(void)
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(pos.x - 10, pos.y - 10);
        glVertex2f(pos.x - 10, pos.y + 10);
        glVertex2f(pos.x + 10, pos.y + 10);
        glVertex2f(pos.x + 10, pos.y - 10);
    glEnd();
}

void
Entity::DrawEllipse(void)
{
    GLfloat angleIncrement = (360.0f / 360) * M_PI / 180.0f;
    glBegin(GL_POINTS);
        GLfloat angle = 0.0f;
        for (size_t _k = 0; _k < 360; ++_k) {
            glVertex2f(pos.x + (10 * cos(angle)), pos.y + (10 * sin(angle)));
            angle += angleIncrement;
        }
    glEnd();
}

void
Entity::DrawTriangle(void)
{
    glBegin(GL_LINE_LOOP);
        glVertex2f(pos.x, pos.y - 10);
        glVertex2f(pos.x - 10, pos.y + 10);
        glVertex2f(pos.x + 10, pos.y + 10);
    glEnd();
}