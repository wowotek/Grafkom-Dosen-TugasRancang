#include "entity.hh"

#include "common.hh"

Entity::Entity(b2Vec2 initPos, b2Vec2 initSize, b2World * worldPointer)
{
    this->pos = initPos;

    this->bodyDef.type = b2_dynamicBody;
    this->bodyDef.position.Set(up2(this->pos));
    this->body = worldPointer->CreateBody(&this->bodyDef);

    this->dynamicBox.SetAsBox(up2(initSize));
    this->fixtureDef.shape = &dynamicBox;
    this->fixtureDef.density = 1.0f;
    this->fixtureDef.friction = 0.3f;
    this->body->CreateFixture(&fixtureDef);
}

// First Constructor Overloader
Entity::Entity(float32 posX, float32 posY, float32 sizeX, float32 sizeY, b2World * worldPointer):
Entity::Entity(b2Vec2(posX, posY), b2Vec2(sizeX, sizeY), worldPointer)
{};