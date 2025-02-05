#ifndef INCLUDE_TINYURDF_WORLD_H_
#define INCLUDE_TINYURDF_WORLD_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <vector>
#include <memory>

#include <loguru/loguru.hpp>

#include "model.h"
#include "object_base.h"
#include "pose.h"
#include "property_base.h"

template<typename... PropertyBase>
class Entity : public ObjectBase
{
public:
  void clear();
private:
  std::shared_ptr<Model> model;
  Pose origin;
};

template<typename... PropertyBase>
class World : public ObjectBase{
public: 
  World();
  void clear();
private:
  std::shared_ptr<std::string> name = nullptr;
  std::vector<Entity<PropertyBase...>> models;
};
#endif //  TINYURDF_WORLD_H_