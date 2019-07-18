#ifndef GAME_HH
#define GAME_HH

#include "common.hh"


void SwitchGravity();

void SetNewEntityType(int);
void AddEntity(vec2f);
void RenderEntities();
void UpdateEntities();

#endif