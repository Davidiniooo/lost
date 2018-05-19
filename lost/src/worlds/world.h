#pragma once

#include "lost.h"

namespace lost::worlds {

namespace layers {}

class world {
public:
  world();
  ~world();

  UPDATE_RENDER

  std::vector<class layers::layer *> m_layers;
};

} // namespace lost
