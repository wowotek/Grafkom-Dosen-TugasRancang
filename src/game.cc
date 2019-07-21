#include "game.hh"
#include <vector>

#include  "entity.hh"

int entityType = ENTITY_SQUARE;
std::vector<Entity> entities;

b2World * world;

void
InitGame(b2World * init_world)
{
    world = init_world;
}

void
SetNewEntityType(int type)
{
    entityType = type;
}

void
AddEntity(vec2f mpos)
{
    entities.push_back(
        Entity(mpos, ENTITY_SQUARE, world)
    );
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
UpdateEntities(int)
{
    world->Step(1.0f/120.0f, 6, 2);

    for(unsigned int i = 0; i < entities.size(); i++)
    {
        entities.at(i).UpdateEntity();
    }
}