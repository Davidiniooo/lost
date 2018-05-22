#include "entity_layer.h"

#include "entities/game_entity.h"

namespace lost::worlds::layers {

entity_layer::entity_layer(std::string n) : layer(n) {
  m_entities = std::vector<lost::entities::game_entity *>();
}

entity_layer::~entity_layer() {}

int entity_layer::update(double dt) {
  for (lost::entities::game_entity *e : m_entities) {
    e->update(dt);
  }
  return 0;
}

int entity_layer::render() {

  return 0;
}

void entity_layer::add_entity(lost::entities::game_entity *e) {
  m_entities.push_back(e);
}

void entity_layer::remove_entity(lost::entities::game_entity *e) {
  int i = 0;
  for (lost::entities::game_entity *_e : m_entities) {
    if (_e == e) {
      m_entities.erase(m_entities.begin() + i);
      delete _e;
      return;
    }
    ++i;
  }
}

} // namespace lost::worlds::layers
