#include "entity_layer.h"

#include "entities/entity.h"

entity_layer::entity_layer() {
  entities = std::vector<entity*>();
}

entity_layer::~entity_layer() {}

int entity_layer::update(double dt) {
  for (entity* e : entities) {
    e->update(dt);
	}
  return 0;
}

int entity_layer::render() {

  return 0;
}

void entity_layer::add_entity(entity* e) {
  entities.push_back(e);
}

void entity_layer::remove_entity(entity* e) {
  int i = 0;
  for (entity* _e : entities) {
    if (_e == e) {
      entities.erase(entities.begin() + i);
			delete _e;
			return;
		}
    ++i;
  }
}