#include "world.h"
#include "layers/layer.h"

namespace lost::worlds {

world::world() {
  m_layers = std::vector<layers::layer *>();
}

world::~world() {}

int world::update(double dt) {
  for (layers::layer *l : m_layers) {
    l->update(dt);
  }
  return 0;
}

int world::render() {
  return 0;
}

} // namespace lost
