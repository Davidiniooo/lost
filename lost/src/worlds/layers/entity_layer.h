#pragma once

#include "SFML/Graphics.hpp"
#include "layer.h"

namespace lost::entities {
class entity;
}

namespace lost::worlds::layers {

class entity_layer : public layer {
public:
  entity_layer();
  ~entity_layer();

  UPDATE_RENDER

  void add_entity(lost::entities::entity *e);
  void remove_entity(lost::entities::entity *e);

  std::vector<lost::entities::entity *> m_entities;
};

} // namespace lost::worlds::layers
