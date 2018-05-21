#include "entity_tilemap.h"
#include "entities/game_entity.h"
#include "math/rect.h"
#include "math/vec2.h"
#include "worlds/layers/tile_layer.h"
#include <math.h>

namespace lost::math::collision {

void entity_tilemap(
    lost::entities::game_entity &e, lost::worlds::layers::tile_layer &t) {
  math::rect e_rect(
      e.m_position.m_x - e.m_half_sizes.m_x,
      e.m_position.m_y - e.m_half_sizes.m_y,
      e.m_half_sizes.m_x * 2.0,
      e.m_half_sizes.m_y * 2.0);

  if (e.m_velocity.m_x != 0) {
    double vhsp =
        e.m_velocity.m_x > 0 ? ceil(e.m_velocity.m_x) : floor(e.m_velocity.m_x);

    double bbox_side_h;

    if (vhsp > 0)
      bbox_side_h = e_rect.right();
    else
      bbox_side_h = e_rect.left();

    bool col = false;

    for (int i = (int)floor(e_rect.top() / t.m_tile_size.y);
         i <= floor(e_rect.bottom() / t.m_tile_size.y);
         ++i) {
      int c = t.get_at_coord(bbox_side_h + vhsp, i * t.m_tile_size.y);

      if (c == 1) {
        col = true;
        break;
      }
    }

    if (col) {
      if (e.m_velocity.m_x > 0) {
        e.m_position.m_x =
            floor((bbox_side_h + vhsp) / t.m_tile_size.x) * t.m_tile_size.x
            + e.m_half_sizes.m_x - 1;
      } else {
        e.m_position.m_x =
            floor((bbox_side_h + vhsp) / t.m_tile_size.x) * t.m_tile_size.x
            + t.m_tile_size.x - e.m_half_sizes.m_x + 1;
      }

      e.m_velocity.m_x = 0;
    }
  }

  if (e.m_velocity.m_y != 0) {
    double vvsp =
        e.m_velocity.m_y > 0 ? ceil(e.m_velocity.m_y) : floor(e.m_velocity.m_y);

    double bbox_side_v;

    if (vvsp > 0)
      bbox_side_v = e_rect.bottom();
    else
      bbox_side_v = e_rect.top();

    bool col = false;

    for (int i = (int)floor(e_rect.left() / t.m_tile_size.x);
         i <= floor(e_rect.right() / t.m_tile_size.x);
         ++i) {
      int c = t.get_at_coord(i * t.m_tile_size.x, bbox_side_v + vvsp);

      if (c == 1) {
        col = true;
        break;
      }
    }

    if (col) {
      if (e.m_velocity.m_y > 0) {
        e.m_position.m_y =
            floor((bbox_side_v + vvsp) / t.m_tile_size.y) * t.m_tile_size.y
            + e.m_half_sizes.m_y - 1;
      } else {
        e.m_position.m_y =
            floor((bbox_side_v + vvsp) / t.m_tile_size.y) * t.m_tile_size.y
            + t.m_tile_size.y - e.m_half_sizes.m_y + 1;
      }

      e.m_velocity.m_y = 0;
    }
  }
}
} // namespace lost::math::collision