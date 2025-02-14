#ifndef INCLUDE_TINYURDF_COMMON_PROPERTY_BASE_H_
#define INCLUDE_TINYURDF_COMMON_PROPERTY_BASE_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <sstream>

class PropertyBase{
 public:
   virtual bool validate() const {return true;};
   virtual std::string toString() const = 0;
 protected:
   PropertyBase() {};
   virtual ~PropertyBase() {};
   virtual bool isA(const char* name) const = 0;
   virtual PropertyBase* getPointer() {return this;};
   virtual PropertyBase& operator=(const PropertyBase& rhs) {return *this;};
   virtual void clear() = 0;
};
#endif // INCLUDE_TINYURDF_COMMON_PROPERTY_BASE_H_