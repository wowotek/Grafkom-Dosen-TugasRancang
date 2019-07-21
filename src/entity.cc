#include "entity.hh"

#include <iostream>


/* ENTITY CLASS IMPLEMENTATION SECTION */

Entity::Entity(float init_x, float init_y, int init_type)
{
    pos = vec2f(init_x, init_y);
    type = init_type;

    Init();
}

Entity::Entity(vec2f init_pos, int init_type)
{
    pos = init_pos;
    type = init_type;

    Init();
}

void Entity::Init(void)
{
    
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

/* BODY CLASS IMPLEMENTATION SECTION */

Body::Body(b2World world, int body_type, int body_shape, vec2f position, vec2f size)
{
    pos = position;

    if(body_type == BODY_STATIC)
    {
        bodyDef.position.Set(unpack2(pos));
        body = world.CreateBody(&bodyDef);
        box.SetAsBox(unpack2(size));
        body->CreateFixture(&box, 0.0f);

    } else
    if(body_type == BODY_DYNAMIC)
    {
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(unpack2(pos));
        body = world.CreateBody(&bodyDef);

        if (body_shape == ENTITY_TRIANGLE)      // TRIANGLE
        {
            b2Vec2 vertices[] = {
                b2Vec2(pos.x, pos.y - 10),
                b2Vec2(pos.x - 10, pos.y + 10),
                b2Vec2(pos.x + 10, pos.y + 10)
            };

            box.Set(vertices, 3);
        } else
        if (body_shape == ENTITY_CIRCLE)        // CIRCLE
        {
            b2Vec2 vertices[360];

            float angleIncrement = (360.0f / 360) * M_PI / 180.0f;
            float angle = 0.0f;
            for (size_t _k = 0; _k < 360; ++_k) {
                vertices[_k] = b2Vec2(pos.x + (10 * cos(angle)), pos.y + (10 * sin(angle)));
                angle += angleIncrement;
            }

            box.Set(vertices, 360);
        } else                                  // SQUARE
        {
            b2Vec2 vertices[] = {
                b2Vec2(pos.x - 10, pos.y - 10),
                b2Vec2(pos.x - 10, pos.y + 10),
                b2Vec2(pos.x + 10, pos.y + 10),
                b2Vec2(pos.x + 10, pos.y - 10)
            };

            box.Set(vertices, 4);
        }

        fixtureDef.shape = &box;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        body->CreateFixture(&fixtureDef);
    }
}