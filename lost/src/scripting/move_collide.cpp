#include "scripting/move_collide.h"
#include "core/game.h"
#include "entities/game_entity.h"
#include "lost.h"
#include "worlds/layers/tile_layer.h"
#include "worlds/world.h"
#include <math.h>
#include "scripting/cpp_get_tile_layer.h"

namespace lost::scripting::funcs {

#define e_x e->m_position.x
#define e_y e->m_position.y
#define e_hsp e->m_velocity.x
#define e_vsp e->m_velocity.y
#define e_width e->m_size.x
#define e_height e->m_size.y

int move_collide(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e =
      (lost::entities::game_entity *)lua_topointer(L, lua_gettop(L));

  // ~ T I L E S E T   C O L L I S I O N ~

  double hitbox_side_h;
  double hitbox_side_v;

  lost::worlds::layers::tile_layer *tile_layer =
      cpp_get_tile_layer("collision");
  double tile_width  = tile_layer->m_tile_size.x;
  double tile_height = tile_layer->m_tile_size.x;

  if (e_hsp != 0) {
    if (e_hsp > 0) {
      hitbox_side_h = e_x + e_width;
    } else {
      hitbox_side_h = e_x;
    }

    bool col = false;

    for (int i = floor(e_y / tile_height);
         i <= floor((e_y + e_height - 1) / tile_height);
         ++i) {

      int c = tile_layer->get_at(
          (int)floor((hitbox_side_h + e_hsp) / tile_width), i);

      if (c == 1) {
        col = true;
        break;
      }
    }

    if (col) {
      if (e_hsp > 0) {
        e_x = tile_layer->x_coord_to_index(hitbox_side_h + e_hsp) * tile_width
              - e_width;
      } else {
        e_x = tile_layer->x_coord_to_index(hitbox_side_h + e_hsp) * tile_width
              + tile_width;
      }

      e_hsp = 0;
    }
  }

  if (e_vsp != 0) {
    if (e_vsp > 0) {
      hitbox_side_v = e_y + e_height;
    } else {
      hitbox_side_v = e_y;
    }

    bool col = false;

    for (int i = floor(e_x / tile_width);
         i <= floor((e_x + e_width - 1) / tile_width);
         ++i) {
      int c =
          tile_layer->get_at(i, floor((hitbox_side_v + e_vsp) / tile_height));

      if (c == 1) {
        col = true;
        break;
      }
    }

    if (col) {
      if (e_vsp > 0) {
        e_y = tile_layer->y_coord_to_index(hitbox_side_v + e_vsp) * tile_height
              - e_height;
      } else {
        e_y = tile_layer->y_coord_to_index(hitbox_side_v + e_vsp) * tile_height
              + tile_height;
      }
      e_vsp = 0;
    }
  }

  // if vsp != 0 {
  // 	var vvsp = vsp > 0 ? ceil(vsp) : floor(vsp)

  // 	if vsp > 0 hitbox_side_v = hitbox_bottom; else hitbox_side_v =
  // hitbox_top;

  // 	if (tilemap_get_at_pixel(tilemap, hitbox_left, hitbox_side_v + vvsp) ==
  // 2) or 		(tilemap_get_at_pixel(tilemap, hitbox_right,
  // hitbox_side_v
  // + vvsp) == 2) {

  // 		if vsp > 0 and
  // 			tilemap_get_cell_y_at_pixel(tilemap, hitbox_left,
  // hitbox_side_v
  // + vvsp) >= hitbox_bottom { 				draw_rectangle
  // (tilemap_get_cell_x_at_pixel(tilemap, hitbox_left, hitbox_side_v + vvsp),
  // tilemap_get_cell_y_at_pixel(tilemap, hitbox_left, hitbox_side_v + vvsp),
  // tilemap_get_cell_x_at_pixel(tilemap, hitbox_left, hitbox_side_v + vvsp) +
  // 15, tilemap_get_cell_y_at_pixel(tilemap, hitbox_left, hitbox_side_v + vvsp)
  // + 15, false) 			y = tilemap_get_cell_y_at_pixel(tilemap,
  // hitbox_left, hitbox_side_v + vvsp) * 16 - sprite_yoffset

  // 			vsp = 0;
  // 		}
  // 	}
  // }

  // // ~ O B J E C T   C O L L I S I O N ~

  // if (place_meeting(x+hsp,y,o_collide)) {
  // 	while(!place_meeting(x+sign(hsp),y,o_collide)) {
  // 		x += sign(hsp);
  // 	}
  // 	hsp = 0;
  // }

  // if (place_meeting(x,y+vsp,o_collide)) {
  // 	while(!place_meeting(x,y+sign(vsp),o_collide)) {
  // 		y += sign(vsp);
  // 	}
  // 	vsp = 0;
  // }

  e_x += e_hsp;
  e_y += e_vsp;

  return 0;
}

#undef e_x
#undef e_y
#undef e_hsp
#undef e_vsp
#undef e_width
#undef e_height

} // namespace lost::scripting::funcs