#pragma once

#include "layer.h"

class game_object;
struct game_object_template;

class obj_layer : public layer {
public:
  obj_layer();
  ~obj_layer();

  UPDATE_RENDER

  void add_obj(game_object_template t);
  void remove_first_obj(uint index);

  std::vector<game_object> objs;
};