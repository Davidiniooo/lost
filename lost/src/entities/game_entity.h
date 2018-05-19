#include "entity.h"
#include "lost.h"
#include "math/vec2.h"

namespace lost::entities {

using namespace lost;

class game_entity {
public:
  game_entity();
  ~game_entity();

  UPDATE_RENDER

  entity *   m_entity;
  math::vec2 m_position;
  math::vec2 m_velocity;
};

} // namespace lost::entities