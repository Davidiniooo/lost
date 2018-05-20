#include "game_entity.h"

namespace lost::entities {

game_entity::game_entity(entity *e, math::vec2 p, math::vec2 v, math::vec2 s)
    : m_entity(e), m_position(p), m_velocity(v), m_half_sizes(s) {}

} // namespace lost::entities