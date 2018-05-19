#include "lost.h"

namespace lost::math {

using namespace lost;

class vec2 {
public:
  vec2() : m_x(0), m_y(0) {}
  vec2(double x, double y) : m_x(x), m_y(y) {}
  ~vec2() {}

  double m_x;
  double m_y;
};

} // namespace lost::math