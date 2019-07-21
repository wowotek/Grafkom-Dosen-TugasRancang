#include "game.hh"
#include <vector>

#include  "entity.hh"

int entityType = ENTITY_SQUARE;
std::vector<Entity> entities;

b2World * world;
b2BodyDef groundBodyDef;
b2Body * groundBody;
b2PolygonShape groundBox;

void
InitGame(b2World * init_world)
{
    world = init_world;

    groundBodyDef.position.Set(0.0f, 600.0f);

    groundBody = world->CreateBody(&groundBodyDef);

    groundBox.SetAsBox(12000.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);
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
        Entity(mpos, entityType, world)
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
UpdateEntities()
{
    for(unsigned int i = 0; i < entities.size(); i++)
    {
        entities.at(i).UpdateEntity();
    }
}