#pragma once

#include "layer.h"

class entity;

class entity_layer : public layer {
public:
  entity_layer();
  ~entity_layer();

  UPDATE_RENDER

  void add_entity(entity* e);
  void remove_entity(entity* e);

  std::vector<entity*> entities;
};