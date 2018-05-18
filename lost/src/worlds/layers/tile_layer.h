#pragma once

#include "layer.h"

class tile_layer : public layer {
  tile_layer();
  ~tile_layer();

  UPDATE_RENDER

  bool load();
}
