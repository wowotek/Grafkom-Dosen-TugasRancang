#include <iostream>
#include "entity.hh"

#include "common.hh"
#include "shape.hh"

unsigned int * texEntP;

void
InitEntityTextures(unsigned int * initTexture)
{
    texEntP = initTexture;
}

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
    this->fixtureDef.restitution = 0.5f;
    this->body->CreateFixture(&fixtureDef);
}

void
Entity::DrawEntity()
{
    if(type==SQUARE){
        Square(body->GetPosition(), size, body->GetAngle(), texEntP[0]);
    } else if (type==TRIANGLE) {
        Triangle(body->GetPosition(), size, body->GetAngle(), texEntP[0]);
    } else if (type==CIRCLE) {
        Circle(body->GetPosition(), size, body->GetAngle(), texEntP[1]);
    }
}

bool
Entity::IsMouseInside(float x, float y)
{
    return (x > body->GetPosition().x - (size/1.5f) && x < body->GetPosition().x + (size/1.5f) &&
       y > body->GetPosition().y - (size/1.5f) && y < body->GetPosition().y + (size/1.5f));
}