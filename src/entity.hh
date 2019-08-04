#ifndef ENTITY_HH
#define ENTITY_HH

#include <Box2D/Box2D.h>

enum EntityType{
    SQUARE,
    TRIANGLE,
    CIRCLE
};

class Entity {
    private:
        b2BodyDef bodyDef;

        b2PolygonShape polygonShape;
        b2CircleShape circleShape;

        b2FixtureDef fixtureDef;

        b2Vec2 pos;
        float size;
        EntityType type;

    public:
        b2Body* body;

        Entity(b2Vec2, float, EntityType, b2World *);

        void DrawEntity();
};

#endif