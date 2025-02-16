#ifndef INCLUDE_TINYURDF_COMMON_OBJECT_BASE_H_
#define INCLUDE_TINYURDF_COMMON_OBJECT_BASE_H_

// Copyright 2025 wissem CHIHA

#include <string>

class ObjectBase {
 public:
  virtual std::string toString() const = 0;
  virtual const char* getTypename() const = 0;
  virtual bool empty() const = 0;
  virtual bool isA(const char* name) const = 0;
  virtual void clear() = 0;
 protected:
  ObjectBase() {}
  virtual ~ObjectBase() {}
  virtual ObjectBase* getPointer() { return this; }
};
#endif  // INCLUDE_TINYURDF_COMMON_OBJECT_BASE_H_
