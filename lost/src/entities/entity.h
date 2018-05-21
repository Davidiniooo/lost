#pragma once

#include "lost.h"

namespace lost::entities {

using namespace lost;

class entity {
public:
  entity();
  ~entity();

  std::string update;
  std::string render;
};

} // namespace lost::entities
