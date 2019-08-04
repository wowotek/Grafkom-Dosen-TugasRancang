#include <iostream>
#include "entity.hh"

#include "common.hh"
#include "shape.hh"

Entity::Entity(b2Vec2 initPos, float initSize, EntityType initType, b2World * worldPointer)
{
    this->pos = initPos;
    this->size = initSize;
    this->type = initType;

    this->bodyDef.type = b2_dynamicBody;
    this->bodyDef.position.Set(up2(this->pos));
    this->body = worldPointer->CreateBody(&this->bodyDef);

    float hs = initSize / 1.5f;
    if(type == SQUARE){
        b2Vec2 vertices[4] = {
            b2Vec2(-hs, -hs),
            b2Vec2(hs, -hs),
            b2Vec2(hs, hs),
            b2Vec2(-hs, hs)
        };
        this->polygonShape.Set(vertices, 4);
        this->fixtureDef.shape = &this->polygonShape;
        std::cout << "Entity((" << initPos.x << " " << initPos.y << ") " << "SQR" << ")" << std::endl;
    } else if (type == TRIANGLE) {
        b2Vec2 vertices[3] = {
            b2Vec2(0, -initSize / 1.0f),
            b2Vec2(-initSize / 1.25f, initSize / 2.0f),
            b2Vec2(initSize / 1.25f, initSize / 2.0f)
        };
        this->polygonShape.Set(vertices, 3);
        this->fixtureDef.shape = &this->polygonShape;
        std::cout << "Entity((" << initPos.x << " " << initPos.y << ") " << "TRI" << ")" << std::endl;
    } else if (type == CIRCLE) {
        this->circleShape.m_p.Set(0, 0);
        this->circleShape.m_radius = initSize;
        this->fixtureDef.shape = &this->circleShape;
        std::cout << "Entity((" << initPos.x << " " << initPos.y << ") " << "CIR" << ")" << std::endl;
    }
    
    this->fixtureDef.density = 1.0f;
    this->fixtureDef.friction = 0.3f;
    this->fixtureDef.restitution = 1.1f;
    this->body->CreateFixture(&fixtureDef);
}

void
Entity::DrawEntity()
{
    // for(b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext())
    // {
    //     b2Shape::Type shapeType = f->GetType();
    //     if(shapeType == b2Shape::e_circle){
    //         b2CircleShape* circleShape = (b2CircleShape*)f->GetShape();
    //     } else if(shapeType == b2Shape::e_polygon){
    //         b2PolygonShape* polygonShape = (b2PolygonShape*)f->GetShape();
    // }

    if(type==SQUARE){
        Square(body->GetPosition(), size, body->GetAngle());
    } else if (type==TRIANGLE) {
        Triangle(body->GetPosition(), size, body->GetAngle());
    } else if (type==CIRCLE) {
        Circle(body->GetPosition(), size, body->GetAngle());

        // std::cout << body->GetPosition().x  << " " << body->GetPosition().y << std::endl;
        // glColor3f(0, 1, 1);
        // glPointSize(5);
        // glBegin(GL_LINES);
        //     glVertex2f(up2(body->GetPosition()));
        //     glVertex2f(up2add(body->GetPosition(), circleShape.m_radius, 0));
        // glEnd();
    }
}