#include "scripting/on_floor.h"
#include "entities/game_entity.h"
#include "scripting/cpp_get_tile_layer.h"
#include "worlds/layers/tile_layer.h"
#include <math.h>

namespace lost::scripting::funcs {

int on_floor(lua_State *L) {
  lua_getglobal(L, "this");
  lost::entities::game_entity *e =
      (lost::entities::game_entity *)lua_topointer(L, lua_gettop(L));

  lost::worlds::layers::tile_layer *tile_layer =
      cpp_get_tile_layer("collision");

  bool col = false;

  for (int i = floor(e->m_position.x / tile_layer->m_tile_size.x);
       i
       <= floor(
              (e->m_position.x + e->m_size.x - 1) / tile_layer->m_tile_size.x);
       ++i) {
    if (tile_layer->get_at(i, floor((e->m_position.y + e->m_size.y) / tile_layer->m_tile_size.y))) {
      col = true;
      break;
    }
  }

  lua_pushboolean(L, col);

      return 1;
}

} // namespace lost::scripting::funcs