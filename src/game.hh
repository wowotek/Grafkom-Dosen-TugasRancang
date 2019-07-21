#ifndef GAME_HH
#define GAME_HH
#include <Box2D/Box2D.h>

#include "common.hh"

void InitGame(b2World *);
void SetNewEntityType(int);
void AddEntity(vec2f);
void RenderEntities();
void UpdateEntities(int);

#endif