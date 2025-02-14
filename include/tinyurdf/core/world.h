#ifndef INCLUDE_TINYURDF_WORLD_H_
#define INCLUDE_TINYURDF_WORLD_H_

// Copyright 2025 Wissem CHIHA

#include <vector>
#include <loguru/loguru.hpp>
#include "core/model.h"
#include "common/object_base.h"
#include "common/property_base.h"
#include "core/pose.h"

/**
 * @brief 
 */
template<typename... PropertyBase>
class Entity : public ObjectBase
{
public:
  void clear();
private:
  std::shared_ptr<Model> model;
  Pose origin;
};

/**
 * @brief 
 */
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