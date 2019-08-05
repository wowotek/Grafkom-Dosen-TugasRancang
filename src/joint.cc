#include "joint.hh"

#include <iostream>
#include <GL/glut.h>

void
Spring::SetWorld(b2World * initWorldP)
{
    this->worldPoint = initWorldP;
}

void
Spring::SetMousePos(b2Vec2 * mousePositionPointer)
{
    this->mousePosition = mousePositionPointer;
}

void
Spring::SetGroundBody()
{
}

void
Spring::Update()
{
    if(this->joint != nullptr || this->joint != NULL)
    {
        this->joint->SetTarget(b2Vec2(this->mousePosition->x, this->mousePosition->y));

        float bx = joint->GetBodyB()->GetPosition().x;
        float by = joint->GetBodyB()->GetPosition().y;

        float ax = joint->GetBodyA()->GetPosition().x;
        float ay = joint->GetBodyA()->GetPosition().y;

        b2Vec2 awp = joint->GetBodyA()->GetWorldPoint(
            b2Vec2(this->mousePosition->x, this->mousePosition->y)
        );

        float mx = mousePosition->x;
        float my = mousePosition->y;
        glLineWidth(10);
        glColor3f(1, 1, 1);
        glBegin(GL_LINES);
            glVertex2f(mx, my);
            glVertex2f(bx, by);
        glEnd();
    }
}

void
Spring::Joint(b2Body * targetBody)
{
    this->bodyB = targetBody;

    this->adef.type = b2_kinematicBody;
    this->adef.position = b2Vec2(this->mousePosition->x, this->mousePosition->y);
    this->adef.fixedRotation = true;
    this->bodyA = this->worldPoint->CreateBody(&this->adef);
    this->bodyA->SetAwake(true);

    this->jointDef.bodyA = this->bodyA;
    this->jointDef.bodyB = targetBody;
    this->jointDef.collideConnected = false;
    this->jointDef.dampingRatio = 0.00001f;
    this->jointDef.frequencyHz = 120.0f;
    this->jointDef.maxForce = 50.0f * targetBody->GetMass();

    this->joint = (b2MouseJoint*)this->worldPoint->CreateJoint(&this->jointDef);
    this->jointed = true;

    std::cout << "Joint has been made !" << std::endl;
}

void
Spring::Detach()
{
    if(this->jointed){
        this->worldPoint->DestroyJoint(this->joint);
        this->jointed = false;
    }
}