#pragma once

#include "lost.h"

namespace lost::worlds::layers {

class layer {
public:
  layer(std::string n) : name(n) {}
  ~layer() {}

  std::string name;

  V_UPDATE_RENDER
};

} // namespace lost
