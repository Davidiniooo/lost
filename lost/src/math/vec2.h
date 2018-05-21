#pragma once

#include "lost.h"

namespace lost::math {

using namespace lost;

class vec2 {
public:
  vec2() : x(0), y(0) {}
  vec2(double _x, double _y) : x(_x), y(_y) {}
  ~vec2() {}

  double x;
  double y;
};

} // namespace lost::math