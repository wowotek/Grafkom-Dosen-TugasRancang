#ifndef ENTITY_HH
#define ENTITY_HH

#include <Box2D/Box2D.h>

class Entity {
    private:
        b2BodyDef bodyDef;
        b2Body* body;
        b2PolygonShape dynamicBox;
        b2FixtureDef fixtureDef;

        b2Vec2 pos;

    public:
        Entity(b2Vec2, b2Vec2, b2World *);
        Entity(float32, float32, float32, float32, b2World *);
};

#endif