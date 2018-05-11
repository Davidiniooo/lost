#include "world.h"
#include "layers/layer.h"

world::world() {
  layers = std::vector<layer*>();
}

world::~world() {}

int world::update(double dt) {
  for (layer *l : layers) {
    l->update(dt);
	}
	return 0;
}

int world::render() {
	return 0;
}