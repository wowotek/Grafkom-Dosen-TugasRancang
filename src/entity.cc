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

    float hs = initSize / 2.0f;
    if(type == SQUARE){
        b2Vec2 vertices[4] = {
            b2Vec2(-hs, -hs),
            b2Vec2(hs, -hs),
            b2Vec2(hs, hs),
            b2Vec2(-hs, hs)
        };
        this->polygonShape.Set(vertices, 4);
        this->fixtureDef.shape = &this->polygonShape;
    } else if (type == TRIANGLE) {
        b2Vec2 vertices[3] = {
            b2Vec2(-hs, hs),
            b2Vec2(hs, hs),
            b2Vec2(hs, -hs),
        };
        this->polygonShape.Set(vertices, 3);
        this->fixtureDef.shape = &this->polygonShape;
    } else if (type == CIRCLE) {
        this->circleShape.m_p.Set(this->pos.x, this->pos.y);
        this->circleShape.m_radius = this->size;
        this->fixtureDef.shape = &this->circleShape;
    }
    
    this->fixtureDef.density = 1.0f;
    this->fixtureDef.friction = 0.3f;
    this->body->CreateFixture(&fixtureDef);
}

void
Entity::DrawEntity()
{
    if(type==SQUARE){
        Square(this->body->GetPosition(), this->size, this->body->GetAngle());
    } else if (type==TRIANGLE) {
        Triangle(this->body->GetPosition(), this->size, this->body->GetAngle());
    } else if (type==CIRCLE) {
        Circle(this->body->GetPosition(), this->size, this->body->GetAngle());
    }
}