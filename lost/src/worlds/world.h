#pragma once

#include "lost.h"

class layer;

class world {
public:
  world();
  ~world();

	UPDATE_RENDER

	std::vector<layer> layers;
};