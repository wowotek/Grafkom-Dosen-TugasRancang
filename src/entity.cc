#include "entity.hh"

#include <iostream>


Entity::Entity(float init_x, float init_y, int init_type, b2World* world)
{
    pos = vec2f(init_x, init_y);
    type = init_type;

    InitPhysicalBody(world, pos);
}

Entity::Entity(vec2f init_pos, int init_type, b2World* world)
{
    pos = init_pos;
    type = init_type;

    InitPhysicalBody(world, pos);
}

void
Entity::InitPhysicalBody(b2World * world, vec2f pos)
{
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(unpack2(pos));
    body = world->CreateBody(&bodyDef);

    if (type == ENTITY_TRIANGLE)      // TRIANGLE
    {
        b2Vec2 vertices[] = {
            b2Vec2(0, -10),
            b2Vec2(-10, 10),
            b2Vec2(10, 10)
        };

        bodyShape.Set(vertices, 3);
    } else
    if (type == ENTITY_CIRCLE)        // CIRCLE
    {
        b2Vec2 vertices[360];

        float angleIncrement = (360.0f / 360) * M_PI / 180.0f;
        float angle = 0.0f;
        for (size_t _k = 0; _k < 360; ++_k) {
            vertices[_k].Set((10 * cos(angle)), (10 * sin(angle)));
            angle += angleIncrement;
        }

        bodyShape.Set(vertices, 360);
    } else                                  // SQUARE
    {
        b2Vec2 vertices[] = {
            b2Vec2(-10, -10),
            b2Vec2(-10, 10),
            b2Vec2(10, 10),
            b2Vec2(10, -10)
        };

        bodyShape.Set(vertices, 4);
    }

    fixtureDef.shape = &bodyShape;
    fixtureDef.density = 0.01f;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 0.3f;
    body->CreateFixture(&fixtureDef);
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
    pos = vec2f(body->GetPosition().x, body->GetPosition().y);
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