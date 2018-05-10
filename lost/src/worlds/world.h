#pragma once

#include "lost.h"
#include "layers/layer.h"

class world {
public:
  world();
  ~world();

	int update(double dt);
	int render();

	std::vector<layer> layers;
};