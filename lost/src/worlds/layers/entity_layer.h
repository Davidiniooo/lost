#pragma once

#include "layer.h"
#include "SFML/Graphics.hpp"

namespace lost::worlds::layers {

class lost::entities::entity;

class entity_layer : public layer {
public:
  entity_layer();
  ~entity_layer();

  UPDATE_RENDER

  void add_entity(lost::entities::entity* e);
  void remove_entity(lost::entities::entity* e);

  std::vector<lost::entities::entity*> entities;
};

}
