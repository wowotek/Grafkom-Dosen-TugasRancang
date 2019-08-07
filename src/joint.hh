/* defining mouse entities joints
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

#ifndef JOINT_HH
#define JOINT_HH

#include <Box2D/Box2D.h>

class Spring {
    private: 
        b2World * worldPoint;

        b2MouseJointDef jointDef;
        b2MouseJoint* joint = nullptr;

        b2BodyDef adef;
        b2Body * bodyA;
        b2Body * bodyB;

        bool jointed = false;

    public:
        b2Vec2 * mousePosition;

        void SetWorld(b2World *);
        void SetMousePos(b2Vec2 *);
        void SetGroundBody();

        void Update();
        void Joint(b2Body *);
        void Detach();
};

#endif