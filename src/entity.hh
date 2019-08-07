/* Definition of all game entities
 * Copyright (C) 2019  Erlangga Ibrahim, Aurelia Gabriele
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef ENTITY_HH
#define ENTITY_HH

#include <Box2D/Box2D.h>

enum EntityType{
    SQUARE,
    TRIANGLE,
    CIRCLE
};

void InitEntityTextures(unsigned int * initTexture);

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
        bool IsMouseInside(float, float);
};

#endif