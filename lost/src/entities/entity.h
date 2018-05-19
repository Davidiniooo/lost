#pragma once

#include "lost.h"

namespace lost::entities {

using namespace lost;

class entity {
public:
  entity();
  ~entity();
  
  UPDATE_RENDER
};

} // namespace lost::entities
