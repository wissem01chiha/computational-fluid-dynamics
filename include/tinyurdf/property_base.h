#ifndef INCLUDE_TINYURDF_PROPERTY_BASE_H_
#define INCLUDE_TINYURDF_PROPERTY_BASE_H_

// Copyright 2025 Wissem CHIHA

#include <iostream>
#include <any>

class PropertyBase{
public:
    virtual bool validate() const {return true;};
    virtual void set(const std::any& value){}; 
protected:
    PropertyBase() {};
    virtual ~PropertyBase() {};
    virtual bool isA(const char* name) = 0;
    virtual PropertyBase* getPointer() {return this;};
    virtual PropertyBase& operator=(const PropertyBase& rhs) {return *this;};
    virtual void clear() = 0;  
    virtual void print(std::ostream& os) = 0;
};
#endif // INCLUDE_TINYURDF_PROPERTY_BASE_H_