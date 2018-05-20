#pragma once

#include "lost.h"

namespace lost::math {
class rect {
public:
  rect() : m_x(0), m_y(0), m_w(0), m_h(0) {}
  rect(double x, double y, double w, double h)
      : m_x(x), m_y(y), m_w(w), m_h(h) {}
  ~rect() {}

  double m_x;
  double m_y;
  double m_w;
  double m_h;

  double left() {
    return m_x;
  }

  double right() {
    return m_x + m_w;
  }

  double top() {
    return m_y;
  }

  double bottom() {
    return m_y + m_h;
  }
};

} // namespace lost::math