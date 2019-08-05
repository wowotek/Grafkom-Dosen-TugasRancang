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