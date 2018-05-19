#include "lost.h"

namespace lost::math {

using namespace lost;

class vec2 {
public:
  vec2(double x, double y);
  ~vec2();

  double m_x;
  double m_y;
};

} // namespace lost::math