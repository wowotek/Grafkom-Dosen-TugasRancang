/* implement entity and mouse spring joint, implement joint.hh
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