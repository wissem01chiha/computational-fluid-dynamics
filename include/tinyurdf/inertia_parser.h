#ifndef INCLUDE_TINYURDF_INERTIA_PARSER_H_
#define INCLUDE_TINYURDF_INERTIA_PARSER_H_

// Copyright 2025 Wissem CHIHA

#include <string>
#include <memory>
#include "inertia.h"
#include "pose_parser.h"
#include "property_parser.h"

/**
 * @brief Parses the link inertia and fills the member variables.
 * 
 * @note This method does not use inertia's safe constructor, so physical 
 * consistency will not be checked! There are no optional elements in the 
 * inertia tag.
 * 
 * @code{.xml}
 * <inertial>
 *   <origin xyz="0 0 0.5" rpy="0 0 0"/>
 *   <mass value="5"/>
 *   <inertia ixx="100" ixy="0" ixz="0" iyy="100" iyz="0" izz="100"/>
 * </inertial>
 * @endcode
 */
class InertiaParser : public ParserBase<Inertia> {
 public:
  InertiaParser();
  void print(std::ostream& os) override;
  bool empty() const override;
  void clear() override;
  const char* getTypename() override;
  bool isA(const char* name) override;
  void parse(const tinyxml2::XMLElement* xml) override;
  std::shared_ptr<Inertia> get() override;
  ~InertiaParser() override = default;
private:
  std::shared_ptr<Inertia> p_;
};
#endif  // INCLUDE_TINYURDF_INERTIA_INERTIA_PARSER_H_
