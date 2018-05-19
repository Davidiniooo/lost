#pragma once

#include "lost.h"

namespace lost::worlds {

namespace layers {
  class layer;
}

class world {
public:
  world();
  ~world();

  UPDATE_RENDER

  std::vector<layers::layer *> m_layers;
};

} // namespace lost
