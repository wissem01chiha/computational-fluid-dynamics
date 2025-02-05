#ifndef INCLUDE_TINYURDF_CORE_OBJECT_BASE_H_
#define INCLUDE_TINYURDF_CORE_OBJECT_BASE_H_

// Copyright 2025 wissem CHIHA

#include <atomic>
#include <iostream>
#include <memory>
#include <string>

class ObjectBase {
public:
virtual void print(std::ostream& os) = 0;
virtual const char* getTypename() = 0;
virtual bool empty() const = 0;
virtual bool isA(const char* name) = 0;
virtual void clear() = 0;

protected:
ObjectBase() {}
virtual ~ObjectBase() {}
virtual ObjectBase* getPointer() { return this; }
};
#endif  // INCLUDE_TINYURDF_CORE_OBJECT_BASE_H_
