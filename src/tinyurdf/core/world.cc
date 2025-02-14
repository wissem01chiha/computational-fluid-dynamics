#include "core/world.h"

template<typename... PropertyBase>
World<PropertyBase...>::World()
{
  name = std::make_shared<std::string>();
}

template<typename... PropertyBase>
void World<PropertyBase...>::clear()
{
  models.clear();
  name.reset();
}
