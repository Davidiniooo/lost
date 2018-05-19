#include "entity_layer.h"

#include "entities/entity.h"

namespace lost::worlds::layers {

entity_layer::entity_layer() {
  entities = std::vector<lost::entities::entity *>();
}

entity_layer::~entity_layer() {}

int entity_layer::update(double dt) {
  for (lost::entities::entity *e : entities) {
    e->update(dt);
  }
  return 0;
}

int entity_layer::render() {

  return 0;
}

void entity_layer::add_entity(lost::entities::entity *e) {
  entities.push_back(e);
}

void entity_layer::remove_entity(lost::entities::entity *e) {
  int i = 0;
  for (lost::entities::entity *_e : entities) {
    if (_e == e) {
      entities.erase(entities.begin() + i);
      delete _e;
      return;
    }
    ++i;
  }
}

} // namespace lost::worlds::layers
