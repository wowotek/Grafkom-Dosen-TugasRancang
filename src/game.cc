#include "game.hh"
#include <vector>

#include  "entity.hh"

bool gravity = true;

void
SwitchGravity()
{
    gravity = !gravity;
}

int entityType = ENTITY_SQUARE;
std::vector<Entity> entities;

void
SetNewEntityType(int type)
{
    entityType = type;
}

void
AddEntity(vec2f mpos)
{
    entities.push_back(Entity(mpos, entityType));
}

void
RenderEntities()
{
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        entities.at(i).DrawEntity();
    }
}

void
UpdateEntities()
{
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        entities.at(i).UpdateEntity();
    }
}