#pragma once

#include "layer.h"

class game_object;

class obj_layer : public layer {
public:
  obj_layer();
  ~obj_layer();

  UPDATE_RENDER

  void add_obj(game_object* obj);
  void remove_first_obj(game_object* obj);

  std::vector<game_object*> objs;
};