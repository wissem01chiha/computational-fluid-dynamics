#ifndef  INCLUDE_TINYURDF_VERSION_H_
#define  INCLUDE_TINYURDF_VERSION_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <vector>
#include <iostream>

#include <loguru/loguru.hpp>

#include "property_base.h"
#include "utils.h"

/// \brief Version handling class.
/// \note Only accepts version strings of the type <major>.<minor>.
/// \todo Update to accept <major>, <minor>, or <major> <minor> (spaced) in a future release.
class Version final : public PropertyBase{
public:
  Version();
  Version(const char *attr);
  Version(const Version& rhs);
  Version& operator=(const Version& rhs);
  bool isA(const char* name) override;
  void clear() override;
  void print(std::ostream& os) override;
  bool equal(double maj, double min);
  double getMajor() const;
  double getMinor() const;
  ~Version();
private:
  double major_, minor_ ;
};
#endif // INCLUDE_TINYURDF_VERSION_H_